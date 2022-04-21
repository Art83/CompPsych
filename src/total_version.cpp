#include <Rcpp.h>
using namespace Rcpp;

//' @title Versions of the game in the batch
//' @param tab  dataframe with two columns "PIN" and "Version"
//' @description function extracts all versions of the game that appeared in the current batch
//' @return returns dataframe with two columns: "PIN" and "version". "PIN" is ids of participants, "Version" is version of the game
//' @export
// [[Rcpp::export]]
DataFrame get_total_versions(DataFrame tab) {
  CharacterVector names = tab.names();
  if(tab.nrow() == 0 || tab.size() == 0){
    stop("Error: you passed an empty table as argument");
  } else if (tab.size() != 2){
    stop("Error: wrong number of dimensions. Dataframe with only two columns is required!");
  } else if (names[0] != "PIN" || names[1] != "version"){
    stop("Error: there's no PIN and/or version column(s)");
  }
  CharacterVector pin = tab["PIN"];
  CharacterVector ver = tab["version"];
  String current_pin = pin[0];
  String current_version = ver[0];
  CharacterVector pin_for_table;
  CharacterVector ver_for_table;
  for(int i = 0; i < pin.length(); i++){
    if(pin[i] != current_pin && i != (pin.length() - 1) ){
      pin_for_table.push_back(current_pin);
      ver_for_table.push_back(current_version);
      current_pin = pin[i];
      current_version = ver[i];
    } else if (pin[i] == current_pin && i == (pin.length() - 1)){
      pin_for_table.push_back(current_pin);
      ver_for_table.push_back(current_version);
    } else {
      continue;
    }
  }
  DataFrame answer = DataFrame::create(Named("PIN") = pin_for_table,
                                       Named("version") = ver_for_table);
  return answer;
}


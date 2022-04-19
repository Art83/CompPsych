
#include <Rcpp.h>
using namespace Rcpp;

//' @title Total time
//' @param tab  dataframe with two columns "PIN" and "timestamp"
//' @description function computes total amount of time spent interacting with the app by subtracting timestamp of last entry from timestamp of each PIN
//' @return returns dataframe with two columns: "PIN" and "time". "PIN" is ids of participants, "Time" is amount of time spent on the game in seconds
//' @export
// [[Rcpp::export]]
DataFrame get_total_time(DataFrame tab) {
  // Check the integrity of the input table
  CharacterVector names = tab.names();
  if(tab.nrow() == 0 || tab.size() == 0){
    stop("Error: you passed an empty table as argument");
  } else if (tab.size() != 2){
    stop("Error: wrong number of dimensions. Dataframe with only two columns is required!");
  } else if (names[0] != "PIN" || names[1] != "timestamp"){
    stop("Error: there's no PIN and/or timestamp column(s)");
  }
  CharacterVector pin = tab["PIN"];
  NumericVector time = tab["timestamp"];
  String current_pin = pin[0];
  int start_time = time[0];
  CharacterVector pin_for_table;
  NumericVector time_for_table;
  for(int i = 0; i < pin.length(); i++){
    if(pin[i] != current_pin && i != (pin.length() - 1) ){
      pin_for_table.push_back(current_pin);
      time_for_table.push_back( (time[i-1])/1000 - start_time/1000);
      current_pin = pin[i];
      start_time = time[i];
    } else if (pin[i] == current_pin && i == (pin.length() - 1)){
      pin_for_table.push_back(current_pin);
      time_for_table.push_back((time[i])/1000 - start_time/1000);
    } else {
      continue;
    }
  }
  DataFrame answer = DataFrame::create(Named("PIN") = pin_for_table,
                                       Named("time") = time_for_table);
  return answer;
}



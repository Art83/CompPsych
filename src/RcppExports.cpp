// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// get_total_time
DataFrame get_total_time(DataFrame tab);
RcppExport SEXP _CompPsych_get_total_time(SEXP tabSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DataFrame >::type tab(tabSEXP);
    rcpp_result_gen = Rcpp::wrap(get_total_time(tab));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_CompPsych_get_total_time", (DL_FUNC) &_CompPsych_get_total_time, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_CompPsych(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

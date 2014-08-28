#include <iostream>
#include <cmath>

//Name: compound
//Description: A compound interest function. P = Present Value
//t = period, n = compounding times per period, r = rate
double compound(double P, double r, double t) {
    if (t > 0) {
        P = P + (P * r); 
        t--;
        compound(P, r, t);
    }   
    else {
        return P;
    }   
}
//Name: compound
//Description: A compound interest function that allows for 
//compounding n times per period
double compound(double P, double r, double t, int n) {
    double S = P * pow(( 1 + (r / n) ), (n * t));
    return S;
}
//Name: cap
//Description: Capitalization Rate Function
//Annual Net Operating Income / Cost( or Value)
double cap(double noi, double v) {
    return noi / v;
}
//Name: cashOnCash
//Description: The first year cash return against the cash invested
//Annual before-tax cash flow / total cash invested
double cashOnCash(double cf, double ci) {
    return (cf / ci);
}
//Name:grossRentMultiplier
//Description: The ratio of sales price over potential rental income
//Price / Potential Gross Income (PotentialRental Income)
double grossRentMultiplier(double p, double pri) {
    return (p / pri);
}
//Name:loanToValue
//Description: Loan to Value. The loan to value ratio is simply
//the ratio of the total loan amount borrowed in relation
//to the value of the property
double loanToValue(double po, double pv) {
    return (po / pv);
}
//Name:debtServiceCoverageRatio
//The debt service coverage ratio is the ratio of the net operating
//income to the annual debt service
double debtServiceCoverageRatio(double noi, double ads){
    return (noi / ads);
}
//Name:operatingExpenseRatio
double operatingExpenseRatio(){
}
//Name:internalRateofReturn
double internalRateofReturn(double x){
}
//Name:netPresentValue
double netPresentValue(){
}
int main() {
    std::cout << "Compiled!" << std::endl;
    return 0;
}



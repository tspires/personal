#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>
//Prototypes
struct RetirementPlan;
double compound(double P, double r, double t);
double compound(double P, double r, double t, int n);
void calculateRetirementTotal(RetirementPlan *plan);
double futureValue(double p, double r, double n);
double futureValueAnnuity(double c, double i, double t);
double random(double min,double max);
//------------------------------------------------------------
//Requirement #21: Demonstrate a struct (used elsewhere)
//------------------------------------------------------------
struct RetirementPlan {
    int currentAge;
    int retirementAge;
    double expectedRoR;
    double currentSavings;
    double contribution;
    double retirementTotal;
    double annuityPayment;
    int * years;

};

//------------------------------------------------------------
//Requirement #24: Demonstrate a pointer to a struct 
//------------------------------------------------------------
void getUserPlan(RetirementPlan *plan) {
    std::cout << "Please enter your current age : ";
    std::cin >> plan->currentAge;
    std::cout << "Please enter your expected retirement age : ";
    std::cin >> plan->retirementAge;
    std::cout << "Please enter your current savings : ";
    std::cin >> plan->currentSavings;
    std::cout << "Please enter your expected annual contribution : ";
    std::cin >> plan->contribution;
    std::cout << "Please enter your expected annual rate of return : ";
    std::cin >> plan->expectedRoR;
}

RetirementPlan newPlan() {
    RetirementPlan plan;
    getUserPlan(&plan);
    return plan;
}

void calculateRetirementTotal(RetirementPlan *plan) {
   int ttr = plan->retirementAge - plan->currentAge;
   plan->retirementTotal = compound(plan->currentSavings,plan->expectedRoR,ttr) + futureValueAnnuity(plan->contribution,plan->expectedRoR,ttr);
}
void calculateAnnuityPayment(RetirementPlan *plan) {
    plan->annuityPayment = plan->retirementTotal * plan->expectedRoR;
}

void calculateYearsValues(RetirementPlan *plan) {
    //------------------------------------------------------------
    //Requirement #19: Demonstrate a dynamic array
    //------------------------------------------------------------
    plan->years = new int[plan->retirementAge];
    for (int i = 0; i < plan->retirementAge; i++) {
        plan->years[i] = futureValueAnnuity(plan->contribution,plan->expectedRoR,i) + compound(plan->currentSavings,plan->expectedRoR,i);
    }
}

void plan() {
    RetirementPlan rPlan = newPlan();
    calculateRetirementTotal(&rPlan);
    calculateAnnuityPayment(&rPlan);
    calculateYearsValues(&rPlan);
    //------------------------------------------------------------
    //Requirement #03: Demonstrate explicit type casting
    //------------------------------------------------------------
    std::cout << std::fixed << std::setprecision(2) << "You would have an estimated $" << (int) rPlan.retirementTotal << " in retirement savings giving you $" << (int) rPlan.annuityPayment << " in withdrawals each year." << std::endl;
}

void cPlan() {
    RetirementPlan rPlan = newPlan();
    double rate =  random(rPlan.expectedRoR-.03,rPlan.expectedRoR+.03);
    std::cout << std::setprecision(2) << "Your average rate in this scenario has changed, based on random market fluctuations, to " << rate << std::endl;
    rPlan.expectedRoR = rate;
    calculateRetirementTotal(&rPlan);
    calculateAnnuityPayment(&rPlan);
    calculateYearsValues(&rPlan);
    std::cout << std::setprecision(2) << std::fixed << std::setprecision(2) << "You would have an estimated $" << (int) rPlan.retirementTotal << " in retirement savings giving you $" << (int) rPlan.annuityPayment << " in withdrawals each year." << std::endl;
}

double futureValueAnnuity(double c, double i, double t) {
    double fv = c * ( ( pow( (1 + i),t) - 1 ) / i );
    return fv;
}
double futureValue(double p, double r, double t) {
    double fv = p * pow((1 + r),t); 
    return fv;
}
//Name: compound
//Description: A compound interest function. P = Present Value
//t = period, n = compounding times per period, r = rate
double compound(double P, double r, double t) {
    if (t > 0) {
        P = P + (P * r); 
        t--;
        //------------------------------------------------------------
        //Requirement #17: Demonstrate Recursion
        //------------------------------------------------------------
        compound(P, r, t);
    }   
    else {
        return P;
    }   
}
//Name: compound
//Description: A compound interest function that allows for 
//compounding n times per period
//------------------------------------------------------------
//Requirement #15: Demonstrate function overloading (Other function above)
//------------------------------------------------------------
double compound(double P, double r, double t, int n) {
    double S = P * pow(( 1 + (r / n) ), (n * t));
    return S;
}


//------------------------------------------------------------
//Requirement #08: Demonstrate a random number
//------------------------------------------------------------
double random(double min,double max) {
    srand(time(NULL));
    double random = ((double) rand()) / (double) RAND_MAX;
    double range = max - min;  
    return (random*range) + min;
}



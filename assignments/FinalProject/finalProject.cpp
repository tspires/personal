#include "menu.cpp"
#include "analysis.cpp"
#include <stdlib.h>
#include <unistd.h>


//Note: Many of the requirements for my project are found in the menu.cpp and analysis.cpp code
//which I import here.
//Reevaluation: For Assignment 6, I have clearly demonstrated my understanding of the topics covered.
//I demonstrate the usage of regular arrays, static and dynamic arrays, cpp and c-style strings,
//passing arrays in functions, array pointers, and command line arguments. This code exists throughout
//the application but is focused in the menu code
//This is demonstrated in the below requirements:
//Requirement #18
//Requirement #19
//Requirement #20
//Requirement #23
void exit(){
}
//-------------------------------------------------------
//Requirement #25: Demonstrate a pointer to an object
//-------------------------------------------------------
void buildMenu(Menu *menu) {
    char applicationName[30] = {'R','e','t','i','r','e','m','e','n','t',' ','S','u','i','t','e','\0'};
    menu->setApplicationName(applicationName);
    MenuItem retirementPlan;
    retirementPlan.setContent("Basic Retirement Plan");
    retirementPlan.setExecution(plan);
    MenuItem contingentPlan;
    contingentPlan.setContent("Contingency Based Plan");
    contingentPlan.setExecution(cPlan);
    MenuItem exitApp;
    exitApp.setContent("Exit");
    exitApp.setExecution(exit);

    menu->addContent('A',retirementPlan);
    menu->addContent('B',contingentPlan);
    menu->addContent('C',exitApp);
}
//-------------------------------------------------------
//Requirement #12: Demonstrate functional decomposition.
//This exists within this application, the thoroughly modularized menu code,
//and the analysis module.
//-------------------------------------------------------
int main(int argc, char *argv[]) {
    //-------------------------------------------------------
    //Requirement #20: Demonstrate a command line argument
    //-------------------------------------------------------
   if (argc <= 1) {
       std::cout << "Usage: " << argv[0] << " <Selection>" << std::endl;
       usleep(3000000);
       Menu menu;
       buildMenu(&menu);
       menu.start();
   }
   else {
       Menu menu;
       buildMenu(&menu);
        //-------------------------------------------------------
        //Requirement #18: Demonstrate a multidimensional array
        //-------------------------------------------------------
       menu.select(argv[1][0]);
   }
}

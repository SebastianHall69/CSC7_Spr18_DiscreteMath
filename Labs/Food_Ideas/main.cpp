/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on April 11, 2018, 8:08 AM
 * Purpose: Find Food For Me When I Can't
 */


//System Libraries
#include <iostream> //ForInput/Output
#include <cstdlib>  //For rand/srand

//Header Files
#include "functions.h"



int main(){
    //Declare Variables
    short choice=0;//Menu Choice Variable
    bool quit=false;//Flag For Leaving Menu, Ending Program
    std::string title="",//Title Of The Program
                menu="";//Main Menu Choices
    std::vector<std::string> bkfst,//Vector Of Breakfast Strings
                             ld,//Vector Of Lunch/Dinner Strings
                             dssrt,//Vector Of Dessert Strings
                             snck;//Vector Of Snack Strings
    
    
    //Initialize Variables
    strngIn(title,menu);//Initialize Title And Menu Strings From A File 
    fillVec(bkfst,ld,dssrt,snck);//Fill Each Vector Of Food Strings
    
    
    //Display Opening Title
    std::cout<<title;//Output Title String
    std::cin.ignore();//Press Enter To Continue
    
    
    //Loop Menu And Options Until User Chooses Exit
    do{ 
        //Display Menu And Get User Choice
        std::cout<<menu<<"Choice: ";//Output Menu
        input(choice);//Get User Input
        
        //Switch Menu Evaluate Choice
        switch(choice){
            case 1:foodOpt(bkfst);break;//Breakfast Options
            case 2:foodOpt(ld);break;//Lunch And Dinner Options
            case 3:foodOpt(dssrt);break;//Dessert Options
            case 4:foodOpt(snck);break;//Snack Options
            case 5:addFood();break;//Add New Food
            case 6:quit=true;break;//Leave The Loop
            default:std::cout<<"Fool\n\n";//Tell Off User
        } 
    }while(quit==false);//End Loop When Quit Is Chosen
    
    //Successful End Program Message
    std::cout<<std::endl<<"So Long\n"
                          "Farewell\n"
                          "Auf Wiedersehen\n"
                          "Goodbye!\n\n";
    
    //A Sebastian Production
    return 0;
}
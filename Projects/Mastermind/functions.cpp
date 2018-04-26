/* 
 * File:   functions.cpp
 * Author: Sebastian Hall
 * Created on April 26, 2018, 1:03 AM
 * Purpose: Hold The Function Definitions For V1 Of The Mastermind Project
 */

//Header Files
#include "functions.h"  //Holds Declarations For Functions
#include <iostream>     //For Input/Output
#include <cstdlib>      //For Random

//Function Declarations
void gmeScrn(std::string r1 [],std::string r2 [],std::string r3 [],
             std::string r4 [],std::string r5 [],std::string r6 [],
             std::string r7 [],std::string r8 [],std::string key [],
             short rghtPos,short rghtClr){
    
    //Output All The Rows In The Game
    std::cout<<"\n\n\n\tMastermind\n";//Game Name Above The Table
    std::cout<<"Row 8 \n";//Row 8
    circle(r8);
    std::cout<<"Row 7 \n";//Row 7
    circle(r7);
    std::cout<<"Row 6 \n";//Row 6
    circle(r6);
    std::cout<<"Row 5 \n";//Row 5
    circle(r5);
    std::cout<<"Row 4 \n";//Row 4
    circle(r4);
    std::cout<<"Row 3 \n";//Row 3
    circle(r3);
    std::cout<<"Row 2 \n";//Row 2
    circle(r2);
    std::cout<<"Row 1 \n";//Row 1
    circle(r1);
    
    //Outputs The Number Of Correct Guesses
    std::cout<<"# Of Correct Colors, But Wrong Position: "<<rghtClr<<"   "
               "# In Correct Position: "<<rghtPos<<std::endl;
    std::cout<<"Press Enter To Continue\n\n\n";//Prompts User To Press Enter
    std::cin.ignore();//Pauses Until Enter Is Pressed
    std::cin.ignore();//Pauses Until Enter Is Pressed
}



void circle(std::string clr []){
    std::cout<<"   ____     ____     ____     ____   \n"
               "  /    \\   /    \\   /    \\   /    \\ \n"
               " /      \\ /      \\ /      \\ /      \\\n"
               " | "<<clr[0]<<"  | | "<<clr[1]<<"  | | "<<
                      clr[2]<<"  | | "<<clr[3]<<"  | \n"
               " \\      / \\      / \\      / \\      / \n"
               "  \\____/   \\____/   \\____/   \\____/  \n";
}




void round(std::string row [],std::string key [],short &rghtClr,short &rghtPos){
    //Declare And Initialize Variables
    short choice=0;//Menu Choice
    const short COLS=4;//The Number Of Columns In The Game, Constant
    
    //Loop For All The Color Choices
    for(int i=0;i<COLS;i++){
        //Output Color Choice Menu
        std::cout<<"\n\n\nColor Choices:\n\n"
                   "1.) Red\n"
                   "2.) Blue\n"
                   "3.) Yellow\n"
                   "4.) Green\n"
                   "5.) Purple\n"
                   "6.) Orange"<<std::endl<<
                   "Enter Your Choice For Circle #"<<i+1<<": ";
        
        //Get User Input
        std::cin>>choice;//Get Color Choice From User
        std::cout<<std::endl<<std::endl<<std::endl<<std::endl;//Move Down 4 Lines
        
        //Enter Value Into Array For Row
        switch(choice){//Evaluates Color Choice
            case 1:row[i]="Red";break;//Adds Chosen Color To Array
            case 2:row[i]="Blu";break;//Adds Chosen Color To Array
            case 3:row[i]="Yel";break;//Adds Chosen Color To Array
            case 4:row[i]="Grn";break;//Adds Chosen Color To Array
            case 5:row[i]="Prp";break;//Adds Chosen Color To Array
            case 6:row[i]="Org";break;//Adds Chosen Color To Array
            default :std::cout<<"Something Happened\n";//Lets Me Know 
        }
    }
    //Update Correctness Of Color And Position After Each Turn
    chckAns(key,row,rghtClr,rghtPos);
}




void setWin(std::string key []){
    //Set Random Seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare And Initialize Variables
    short color=0;//Color To Be Added To Row Array
    short const COLS=4;//The Number Of Columns In The Game, Constant
    
    //Fill Each Element
    for(int i=0;i<COLS;i++){
        color=rand()%6;//Random Value Range [0-5] For Each Color Option
        
        //Use Switch Case To Choose Color For Key
        switch(color){//Evaluates Random Color Choice With Switch
            case 0:key[i]="Red";break;//Adds Random Color To Key
            case 1:key[i]="Blu";break;//Adds Random Color To Key
            case 2:key[i]="Yel";break;//Adds Random Color To Key
            case 3:key[i]="Grn";break;//Adds Random Color To Key
            case 4:key[i]="Prp";break;//Adds Random Color To Key
            case 5:key[i]="Org";break;//Adds Random Color To Key
        }
    }
}




void chckAns(std::string key [],std::string row [],short &rghtClr,short &rghtPos){
    //Declare And Initialize Variables
    bool kRed=false,//Yes/No Red Color Is Present In Key
         kBlu=false,//Yes/No Blue Color Is Present In Key
         kYel=false,//Yes/No Yellow Color Is Present In Key
         kGrn=false,//Yes/No Greed Color Is Present In Key
         kPrp=false,//Yes/No Purple Color Is Present In Key
         kOrg=false,//Yes/No Orange Color Is Present In Key
         rRed=false,//Yes/No Red Color Is Present In Row
         rBlu=false,//Yes/No Blue Color Is Present In Row
         rYel=false,//Yes/No Yellow Color Is Present In Row
         rGrn=false,//Yes/No Greed Color Is Present In Row
         rPrp=false,//Yes/No Purple Color Is Present In Row
         rOrg=false;//Yes/No Orange Color Is Present In Row
    short const COLS=4;//The Number Of Columns In The Game, Constant
    rghtClr=0;//Reset Value For Each Round
    rghtPos=0;//Reset Value For Each Round
    
    //Check If Any Are In The Right Position
    for(int i=0;i<COLS;i++)//For Each Circle In The Row
        if(row[i]==key[i])//If They Have The Same Color Value
            rghtPos++;//Increment The Correct Position Variable
    
    //Check Which Colors Are Present In The Answer Key
    for(int i=0;i<COLS;i++){//For Each Circle In The Row
        if(key[i]=="Red")//If Red Is Present
            kRed=true;//Mark Red Flag True
        else if(key[i]=="Blu")//If Blue Is Present
            kBlu=true;//Mark Blue Flag True
        else if(key[i]=="Yel")//If Yellow Is Present
            kYel=true;//Mark Yellow Flag True
        else if(key[i]=="Grn")//If Green Is Present
            kGrn=true;//Mark Green Flag True
        else if(key[i]=="Prp")//If Purple Is Present
            kPrp=true;//Mark Purple Flag True
        else if(key[i]=="Org")//If Orange Is Present
            kOrg=true;//Mark Orange Flag True
    }
    
    //Check Which Colors Are Present In The Current Row
    for(int i=0;i<COLS;i++){//For Each Circle In The Row
        if(row[i]=="Red")//If Red Is Present
            rRed=true;//Mark Red Flag True
        else if(row[i]=="Blu")//If Blue Is Present
            rBlu=true;//Mark Blue Flag True
        else if(row[i]=="Yel")//If Yellow Is Present
            rYel=true;//Mark Yellow Flag True
        else if(row[i]=="Grn")//If Green Is Present
            rGrn=true;//Mark Green Flag True
        else if(row[i]=="Prp")//If Purple Is Present
            rPrp=true;//Mark Purple Flag True
        else if(row[i]=="Org")//If Orange Is Present
            rOrg=true;//Mark Orange Flag True
    }
    
    //Check If Any Of The Correct Colors Are Matching And Increment If So
    if(kRed&&rRed)//If Both Red Flags Are True
        rghtClr++;//Increment The Right Color Variable
    if(kBlu&&rBlu)//If Both Blue Flags Are True
        rghtClr++;//Increment The Right Color Variable
    if(kYel&&rYel)//If Both Yellow Flags Are True
        rghtClr++;//Increment The Right Color Variable
    if(kGrn&&rGrn)//If Both Green Flags Are True
        rghtClr++;//Increment The Right Color Variable
    if(kPrp&&rPrp)//If Both Purple Flags Are True
        rghtClr++;//Increment The Right Color Variable
    if(kOrg&&rOrg)//If Both Orange Flags Are True
        rghtClr++;//Increment The Right Color Variable
    
    //Subtract Correct Position From Correct Color For Right Answer
    rghtClr-=rghtPos;
}



void wchRow(std::string r1 [],std::string r2 [],std::string r3 [],
            std::string r4 [],std::string r5 [],std::string r6 [],
            std::string r7 [],std::string r8 [],std::string key [],
            short &rghtPos,short &rghtClr,short index){
    //Use The Right Row For The Right Rounds
    switch(index){
        case 0 :round(r1,key,rghtClr,rghtPos);break;//Use r1 For Round 1
        case 1 :round(r2,key,rghtClr,rghtPos);break;//Use r2 For Round 2
        case 2 :round(r3,key,rghtClr,rghtPos);break;//Use r3 For Round 3
        case 3 :round(r4,key,rghtClr,rghtPos);break;//Use r4 For Round 4
        case 4 :round(r5,key,rghtClr,rghtPos);break;//Use r5 For Round 5
        case 5 :round(r6,key,rghtClr,rghtPos);break;//Use r6 For Round 6
        case 6 :round(r7,key,rghtClr,rghtPos);break;//Use r7 For Round 7
        case 7 :round(r8,key,rghtClr,rghtPos);break;//Use r8 For Round 8
        default : std::cout<<"Something Went Wrong In wchRow\n";
    }
}
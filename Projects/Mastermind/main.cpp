/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on April 25, 2018, 6:48 PM
 * Purpose: Mastermind Computer Game Replica With 6 Colors,
 *          4 Columns, And 8 Rows
 */

//System Libraries
#include <iostream> //For Output

//Header Files
#include "functions.h"



int main(){
    //Declare And Initialize Variables
    short const COLS=4;//The Number Of Columns In The Game, Constant
    std::string r1 [COLS]={"   ","   ","   ","   "},//First Row In The Game
                r2 [COLS]={"   ","   ","   ","   "},//Second  "    "    "
                r3 [COLS]={"   ","   ","   ","   "},//Third   "    "    "
                r4 [COLS]={"   ","   ","   ","   "},//Fourth  "    "    "
                r5 [COLS]={"   ","   ","   ","   "},//Fifth   "    "    "
                r6 [COLS]={"   ","   ","   ","   "},//Sixth   "    "    "
                r7 [COLS]={"   ","   ","   ","   "},//Seventh "    "    "
                r8 [COLS]={"   ","   ","   ","   "},//Eighth  "    "    "
                key [COLS]={"   ","   ","   ","   "};//Game Winning Answer Key
    short rghtClr=0,//Number Of Correct Color, But Not Position
          rghtPos=0,//Number In Correct Position
          index=0,//Index For Looping Through The Rounds
          choice=0,//Menu Choice Variable
          rounds=8;//Number Of Rounds In The Game
    bool gameWin=false;//Boolean Value If The Game Is Won Or Not
            
    
    //Initialize Game Winning Key
    setWin(key);//Initialize Key Array
    
    //Display Game Title 
    std::cout<<"\tWelcome To Mastermind\n"
               "\tPress Enter To Begin"<<std::endl;//Prompts User To Enter
    std::cin.ignore();//Pauses Until Enter Is Hit
    
    //Loop Game Rounds
    do{//Do Until User Chooses To Or Must Leave Game
        do{//Do Until The Current Round Is Completed
            //Output Main Play Menu
            std::cout<<"1.) Play Round "<<index+1<<std::endl<<      
                       "2.) View Current Game Screen"<<std::endl<<
                       "3.) Quit The Game Early"<<std::endl<<
                       "\nChoice: ";

            //Get User Choice
            std::cin>>choice;//User Inputs Menu Choice

            //Evaluate User Choice
            switch(choice){
                case 1:wchRow(r1,r2,r3,r4,r5,r6,r7,r8,key,rghtPos,rghtClr,index);break;
                case 2:gmeScrn(r1,r2,r3,r4,r5,r6,r7,r8,key,rghtPos,rghtClr);break;
                case 3:std::cout<<"Farewell, Quitter\n\n\n";break;//Say Goodbye
            }
        }while(choice==2);//While Just Choosing To See Game Board
        
        //Check If User Won The Game
        if(rghtPos==4)//If All Are In The Right Position
            gameWin=true;//Set Gamewin Boolean To True
        
        //Increment Index
        index++;//Index Incremented By 1
    }while(index<rounds&&!gameWin&&choice!=3);//While Not Any Ending Conditions
    
    
    
    //Acknowledge Users Win/Loss
    std::cout<<"Round "<<index<<std::endl;
    if(gameWin)//If The Game Was Won
        std::cout<<"Congratulations, You Won!\n";//Congratulate Winner
    else//Else The Game Was Lost
        std::cout<<"Congratulations, You Lost!\n";//Mock Winner
    
    //Output Correct Answer To The Game
    std::cout<<"\nCorrect Answer\n";
    circle(key);//Output Correct Answer To The Game
    
    
    //A Sebastian Production
    return 0;
}
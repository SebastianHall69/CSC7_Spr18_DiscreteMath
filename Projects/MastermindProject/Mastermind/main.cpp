/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on April 25, 2018, 6:48 PM
 * Purpose: Mastermind Computer Game Replica With 6 Colors,
 *          4 Columns, And 8 Rows
 */

//System Libraries
#include <iostream> //For Output
#include <cstdlib>  //For Random Functions
#include <limits>   //For numeric_limits

//User Libraries
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
    bool gameWin=false,//Boolean Value If The Game Is Won Or Not
         error=false;//Boolean Value If Error In User Input
    setWin(key);//Initialize Key Array
    
    
    //Display Game Title 
    std::cout<<"\tWelcome To Mastermind\n"
               "\tPress Enter To Begin"<<std::endl;//Prompts User To Enter
    std::cin.ignore();//Pauses Until Enter Is Hit
    
    
    //Loop Game Rounds
    do{//Do Until User Chooses To Or Must Leave Game
        do{//Do Until The Current Round Is Completed
            try{
                //Reset Error Flag
                error=false;
                
                //Output Main Play Menu
                std::cout<<"1.) View The Game Board"<<std::endl<<
                           "2.) Play Round "<<index+1<<std::endl<<
                           "3.) Quit The Game Early"<<std::endl<<
                           "\nChoice: ";

                //Get User Choice
                std::cin>>choice;//User Inputs Menu Choice
                
                if(std::cin.fail()||choice<1||choice>3){
                    std::cin.clear();//Remove Any Buffer Error States
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    throw 0;//Throw Exception
                }
            }
            catch(int x){//Catch Exception
                std::cout<<"\n\nThat's Not An Option Here\n\n";//Tell User
                error=true;//Set Error Flag To True
            }

            //Evaluate User Choice
            switch(choice){
                case 1:gmeScrn(r1,r2,r3,r4,r5,r6,r7,r8,
                               key,rghtPos,rghtClr);break;//Output The Board
                case 2:wchRow(r1,r2,r3,r4,r5,r6,r7,r8,
                               key,rghtPos,rghtClr,index);break;//Play Round
                case 3:std::cout<<"Farewell, Quitter\n\n\n";break;//Say Goodbye
            }
        }while(choice==1||error==true);//While Just Choosing To See Game Board
        
        //Check If User Won The Game
        if(rghtPos==4)//If All Are In The Right Position
            gameWin=true;//Set gameWin Boolean To True
        
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



//Function Definitions
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
    std::cout<<"Correct Color, But Wrong Position: "<<rghtClr<<std::endl
             <<"Correct Color In Correct Position: "<<rghtPos<<std::endl;
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
    bool error=false;
    
    //Loop For All The Color Choices
    for(int i=0;i<COLS;i++){
        
        //Get Color Choice From User With Exception Loop
        do{
            try{
                //Reset Error Flag
                error=false;
                
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

                //Attempt To Catch And Fix Buffer Error
                if(std::cin.fail()||choice<1||choice>6){//If Char Or Bad Range
                    std::cin.clear();//Clear Any Error Flags From cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    error=true;//Set Error Flag To Continue Looping
                    throw 0;//Throw Exception With Dummy Variable
                }
            }
            catch(int x){//Catch Exception
                std::cout<<std::endl<<std::endl<<"It Appears You"//Output Error
                        " Entered Something That You Should Not Have";//Message
            }
        }while(error==true);//Continue Looping While Error State Is True
        
        //Enter Value Into Array For Row
        std::cout<<std::endl<<std::endl<<std::endl<<std::endl;//Move Down 4 Lines
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




void chckAns(std::string key [],std::string row [],short &rghtClr,short &rghtPos)   {
    //Declare And Initialize Variables
    enum Colors {RED,BLU,YEL,GRN,PRP,ORG};//Enumerator For Colors
    short kColor [6]={0,0,0,0,0,0},//Holds The Active Number Of Colors In Key
          rColor [6]={0,0,0,0,0,0};//Holds The Active Number Of Colors In Current Row
    short const COLS=4;//The Number Of Columns In The Game, Constant
    rghtClr=0;//Reset Value For Each Round
    rghtPos=0;//Reset Value For Each Round
    
    //Set All Color Values Into Arrays And Right Color/Pos Variables
    for(int i=0;i<COLS;i++){
        //Fill Right Pos Variable
        if(row[i]==key[i])//If The Value In Key Is Equivalent To Row
            rghtPos++;//Right Position Is Incremented
        
        //Count The Number Of Color Each In The Key Array
        if(key[i]=="Red")//If The Color Is Red
            kColor[RED]++;//Increment The Count Of That Color
        else if(key[i]=="Blu")//If The Color Is Blue
            kColor[BLU]++;//Increment The Count Of That Color
        else if(key[i]=="Yel")//If The Color Is Yellow
            kColor[YEL]++;//Increment The Count Of That Color
        else if(key[i]=="Grn")//If The Color Is Green
            kColor[GRN]++;//Increment The Count Of That Color
        else if(key[i]=="Prp")//If The Color Is Purple
            kColor[PRP]++;//Increment The Count Of That Color
        else if(key[i]=="Org")//If The Color Is Orange
            kColor[ORG]++;//Increment The Count Of That Color
        
        //Count The Number Of Color Each In The Row Array
        if(row[i]=="Red")//If The Color Is Red
            rColor[RED]++;//Increment The Count Of That Color
        else if(row[i]=="Blu")//If The Color Is Blue
            rColor[BLU]++;//Increment The Count Of That Color
        else if(row[i]=="Yel")//If The Color Is Yellow
            rColor[YEL]++;//Increment The Count Of That Color
        else if(row[i]=="Grn")//If The Color Is Green
            rColor[GRN]++;//Increment The Count Of That Color
        else if(row[i]=="Prp")//If The Color Is Purple
            rColor[PRP]++;//Increment The Count Of That Color
        else if(row[i]=="Org")//If The Color Is Orange
            rColor[ORG]++;//Increment The Count Of That Color   
    }
    
    //Calculate The Number Of Correct Colors
    for(int i=0;i<6;i++)//For Each Of The Six Color Possibilities
        if(kColor[i]>0&&rColor[i]>0){//If Both The Row & Key Have Common Color
            if(kColor[i]>rColor[i])//If Key Has More Color Than Row
                rghtClr+=rColor[i];//Add Rows Color Value To Right Color
            else                   //If Row Has More Than The Key
                rghtClr+=kColor[i];//Add The Keys Value On
   }
    
    //Adjust For Correct Color, But Wrong Position
    rghtClr-=rghtPos;//Subtract The Number In Right Position From Right Color
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
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//System Libraries
#include <iostream> //ForInput/Output
#include <cstdlib>  //For Random Functions
#include <fstream>  //For Saving Food Ideas
#include <limits>   //For numeric_limits For Exception Handling

//Header Files
#include "functions.h"


//Save Food Function
void svFood(std::string fName,std::string meal){
    //Declare Variables
    std::ofstream file;//File Object To Be Written To
    
    
    //Open File
    file.open(fName.c_str(),std::ios::out|std::ios::app);//Open To Output/Append
    
    
    //Write String To File
    file<<meal<<std::endl;
    
        
    //Close File
    file.close();  
}



//Add Food Function
void addFood(){
    //Declare Variables
    std::ofstream file;//File Object To Write New Food Ideas To
    short choice=0;//User Food Choice
    std::string meal="";//New Meal To Be Added
    enum Food {BRKFST=1,LINNER,DESSERT,SNACK};//Enum Because Why Not?
    
    
    //Get User's Food Choice For New Food To Add
    do{
        //Prompt User Input For Food Type
        std::cout<<std::endl<<std::endl;
        std::cout<<"Which Food Type Would You Like To Add?\n"
                   "1.) Breakfast\n"
                   "2.) Lunch And Dinner\n"
                   "3.) Dessert\n"
                   "4.) Snack"<<std::endl;
        std::cout<<"Choice: ";
        input(choice);//Get User Choice Input

        //If An Invalid Number Is Chosen
        if(choice<BRKFST||choice>SNACK)
            std::cout<<"Invalid, Enter Again\n\n";
    }
    while(choice<BRKFST||choice>SNACK);
    
    
    //Get Users New Food Entry
    std::cout<<"Enter Your New "<<enumTxt(choice)<<std::endl<<"Food: ";
    std::cin.ignore();//Clear Buffer Errors
    getline(std::cin,meal);//Get String From User
    
    
    //Determine File To Write To
    if(choice==BRKFST)          //If Breakfast Is Chosen
        svFood("Breakfast.txt",meal);//Write Meal To Breakfast File
    else if(choice==LINNER)     //If Lunch And Dinner Is Chosen
        svFood("Lunch_And_Dinner.txt",meal);//Write Meal To Linner File
    else if(choice==DESSERT)    //If Dessert Is Chosen
        svFood("Dessert.txt",meal);//Write Meal To Dessert File
    else                        //If Snack Is Chosen
        svFood("Snacks.txt",meal);//Write Meal To Snack File
    
    //Aesthetic Spacing
    as();
}



//Enum To Text Function
std::string enumTxt(short choice){
    //Declare Variables
    enum Food {BRKFST=1,LINNER,DESSERT};//Enum Because Why Not?
    std::string text="";//Text To Be Returned On Choice
    
    
    //Evaluate Choice
    if(choice==BRKFST)          //If Breakfast Is Chosen
        text="Breakfast Food";
    else if(choice==LINNER)     //If Lunch And Dinner Is Chosen
        text="Lunch And Dinner Food";
    else if(choice==DESSERT)    //If Dessert Is Chosen
        text="Dessert";
    else                        //If Snack Is Chosen
        text="Snack";
    
    
    //Return Text On Choice
    return text;     
}



//Input String From File Function
void strngIn(std::string &title,std::string &menu){
    //Declare Variables
    std::ifstream file;//Stream Object For Reading/Writing Files
    
    
    //Write Title To String From File
    file.open("Title.txt",std::ios::in);//Open File
    if(file){//If Successfully Opened
        getline(file,title,'\0');//Read Title Into String
        file.close();//Close File
    }
    else//Else Report Failure To Open File
        std::cout<<"Error Opening File: Title.txt"<<std::endl;
    
    
    
    //Write Menu To String From File
    file.open("Menu_Options.txt",std::ios::in);
    if(file){//If Opened Successfully
        getline(file,menu,'\0');//Read File Into Menu String
        file.close();//Close File
    }
    else//Else Report Failure To Open File
        std::cout<<"Error Opening File: MenuOptions.txt";
}



void vectIn(std::string fName,std::vector<std::string> &array){
    //Declare Variables
    std::fstream file;//File Object To Fill Vectors
    std::string temp="";//Intermediate Between File And Vector

    
    //Open File
    file.open(fName.c_str(),std::ios::in);//Open File
    if(!file){      //If File Could Not Be Opened
        std::cout<<"File: "<<fName<<" Could Not Be Opened Or "//Error
                                    "Does Not Exist"<<std::endl;//Message
        return;//Exit Function
    }
    
    
    //Copy Contents Into File
    getline(file,temp,'\n');        //Copy First String Into Vector
        while(file){                //While Successful Read Operation
            array.push_back(temp);  //Append String To Vector
            getline(file,temp,'\n');//Get Next String From File
        }
    
    
    //Close File
    file.close(); 
}



void fillVec(std::vector<std::string> &bkfst,std::vector<std::string> &ld
            ,std::vector<std::string> &dssrt,std::vector<std::string> &snck){
    //Declare Variables
    std::string fName="";
    
    //Fill Breakfast Food Vector From File Breakfast.txt
    fName="Breakfast.txt";//Set File Name
    vectIn(fName,bkfst);
    
    
    //Fill Lunch And Dinner Vector From File Lunch_And_Dinner.txt
    fName="Lunch_And_Dinner.txt";//Set File Name
    vectIn(fName,ld);
    
    
    //Fill Dessert Vector From File Dessert.txt
    fName="Dessert.txt";//Set File Name
    vectIn(fName,dssrt);
    
    
    //Fill Snacks Vector From File Snacks.txt
    fName="Snacks.txt";//Set File Name
    vectIn(fName,snck);   
}



void foodOpt(const std::vector<std::string> &array){
    //Set Random Seed
    srand(static_cast<unsigned>(time(0)));
    
    
    //Declare Variables
    short index=0;//Randomly Selected Index For Random Food
    short choice=0,size=array.size();//Menu Choice, Vector Size
    
    
    //Aesthetic Spacing
    std::cout<<std::endl<<std::endl<<std::endl;//Move Down Three Lines
    
    
    //Check If Vector Exists
    if(size<=0){//If Array Is Empty
        std::cout<<"No Food To List"<<std::endl;
        as();//Aesthetic Spacing
        std::cin.ignore();//Pause Until Entered
        return;//Return From The Function
    }
    
    
    //Allow User To Choose Option 
    std::cout<<"1.) View Random Food Choice\n"//Output Choices
               "2.) View All Food Choices"<<std::endl<<
               "Choice: ";
    input(choice);//Get User Choice
    std::cout<<std::endl<<std::endl;//Two New Lines
    
    
    //Evaluate Choice With Switch Statement
    switch(choice){
        case 1:{
            //Get Random Food To Output
            index=rand()%size;
            
            //Output Random Food
            std::cout<<"Food: "<<array[index]<<std::endl<<std::endl;
        };break;
        
        case 2:{
            //Loop Through All Food Options
            for(;index<array.size();index++)//From 0 To Size Of Vector
                std::cout<<index+1<<".) "<<array[index]<<std::endl;//Output All
        }break;
        default:std::cout<<"Wrong Choice, Buddy"<<std::endl; break;//Error
    }
    
    //Aesthetic Spacing
    as();
    std::cin.ignore();
}



//Aesthetic Spacing
void as(){
    //Move Down Three Lines And Allow User To Choose When To Continue
    std::cout<<"Press Enter To Continue"<<std::endl<<std::endl<<std::endl;
    std::cin.ignore();//Pause Until User Presses Enter
}


//Processed Input Function
void input(short &choice){
    //Declare And Initialize Variables
    std::string error="\nOnly Use Numeric Input";
    
    //Input With Exception Handling For Characters
    try{
        std::cin>>choice;//Input User Choice
        if(std::cin.fail())//If Keyboard Buffer Breaks From Bad Input
            throw error;//Throw Error String
    }
    catch(std::string error){
        //Fix Stream
        std::cin.clear();//Resets cin Bit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        //Display Error Message
        std::cout<<error<<std::endl;
    }
}
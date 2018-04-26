/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 *
 * Created on March 4, 2018, 8:19 PM
 */


//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;



//Global Variables
enum crdCard {AMERICAN_EXPRESS, VISA, MASTERCARD,ALL};//Enum For Card Types



//Function Prototypes
char *genCard(crdCard);//Generate Card Number, Returns Pointer To That Card
void flipDig(char *);//Flip A Random Card Digit
bool luhn(char *);//Checks A Cards Validity, Returns True For Valid 




int main(){
    //Setting Random Seed
    srand(static_cast<unsigned>(time(0)));//Set Rand With Unsigned Time
    
    
    
    //Declare And Initialize Variables
    const int LOOPS=100;//Number Of Times It Will Loop
    crdCard choice;//Enum That Decides Card Made
    char *card=NULL;//Pointer To Array Of Card Numbers
    int valid=0,invalid=0;//Counts The Number Of Valid/Invalid Cards
    
    
    
    //Generate And Test Each Credit Card
    for(int i=0;i<LOOPS;i++){//For The Specified Number Of Loops
        choice=static_cast<crdCard>(rand()%4);//Give A Random Choice Each Loop
        card=genCard(choice);//Generate The Card With An Enum Specifying Type
        flipDig(card);      //Flip One Random Digit In The Card
        if(luhn(card)){      //If The Card Number Is Still Valid
            valid++;
            cout<<"Valid: "<<card<<endl;
        }//Increment Valid Cards Counter
        else                //Else
            invalid++;      //Increment Invalid Cards Counter
        delete [] card;     //Delete Dynamically Allocated Data
    }
    
    
    
    //Output The Results
    cout<<"Out Of "<<LOOPS<<" Credit Cards: "<<endl;//State Number Of Loops
    cout<<"Valid Cards:   "<<valid<<endl;//Output The Valid Card Count
    cout<<"Invalid Cards: "<<invalid<<endl;//Output The Invalid Card Count
    
    
    //A Sebastian Production
    return 0;
}


//*****************************************
//  Generate Card Number Function         *
//  Returns A Pointer To Generated char   *
//  Array                                 *
//*****************************************

char *genCard(crdCard choice){
    //Declare And Initialize Variables
    char *card=NULL,*temp=NULL;//Pointer For Variable Size Card
    short size=0,sum=0;//Size Of The Card Chosen, Sum For Luhn Check
    short index=0,check=0;//Counting Index To Fill Card Array, Check Digit
    
    
    //Set To Random Card Choice If All Is Chosen
    if(choice==ALL)
        choice=static_cast<crdCard>(rand()%3);
        
    
    //**************************************    
    //Determine Card Type And Create Card  *
    //**************************************
    
    //Evaluate Enum Choice With Switch Case
    switch(choice){
        
        
        //Cases For Four Card Options
        case MASTERCARD:{
            //Set Length For Mastercards
            size=16;//Length Of MasterCards
            
            //Dynamically Allocate char Array For Card
            card=new char[size+1];//For Size Of Card Plus Null Terminator
           
            
            
            //Set Beginning Values Into Card
            card[index++]='5';//First ID Number Is 5, Increment Index
            card[index++]=static_cast<char>(rand()%5+49);//Second ID Num [1-5]
            
            
            //Fill Remaining Card Array With Random Numbers
            for(;index<size;index++)//For The Size Of The Array Minus 1
                card[index]=static_cast<char>(rand()%10+48);//Fill With Num
            card[index]='\0';//End With Null Terminator
            
        }break;
        
        case VISA:{
            //Set Length For Visa Cards
            size=(rand()%3)*3+13;//Length Of Visa Can Be 13,16,19
            
            
            //Dynamically Allocate char Array For Card
            card=new char[size+1];//For Size Of Card Plus Null Terminator
           
            
            //Set Beginning Values Into Card
            card[index++]='4';//Identifying Number Is 4, Increment Index
            
            
            //Fill Remaining Card Array With Random Numbers
            for(;index<size;index++)//For The Size Of The Array Minus 1
                card[index]=static_cast<char>(rand()%10+48);//Fill With Num
            card[index]='\0';//End With Null Terminator
            
        }break;
        
        case AMERICAN_EXPRESS:{
            //Set Length For American Express
            size=15;//Length Of American Express Card
            
            //Dynamically Allocate char Array For Card
            card=new char[size+1];//For Size Of Card Plus Null Terminator
           
            
            //Set Beginning Values Into Card
            card[index++]='3';//First ID Number Is 3, Increment Index
            card[index++]=(rand()%2)?'4':'7';//Second ID Num 4 Or 7
            
            
            //Fill Remaining Card Array With Random Numbers
            for(;index<size;index++)//For The Size Of The Array Minus 1
                card[index]=static_cast<char>(rand()%10+48);//Fill With Num
            card[index]='\0';//End With Null Terminator
            
        }break;
        
        default:cout<<"Somehow I Messed Up"<<endl;//Just In Case   
    }
    
    //******************************************   
    //Make Card Number Valid With Check Digit  *
    //******************************************
    
    
    //Reset Index Value And Seek Second To Last Digit In Card
    index=0;//Reset Index To Zero
    while(card[index+2]!='\0')//While Before The 2nd To Last Digit
        index++;//Increment Index
    
    
    //Fill Temp Array To Calculate
    temp=new char[size+1];//Dynamically Allocate Space For Temp Card
    for(int i=0;i<size+1;i++){//For The Size Of The Card Array
        temp[i]=card[i];//Copy Each Card Value Into Temp
    }
    
    
    //Modify Temporary Card Number 
    for(;index>=0;index-=2){//For Every Other Number Starting From The End
        sum=(temp[index]-48)*2;//Sum Equals Each Element Times Two
        if(sum>9)              //If The Sum Is Greater Than 9
            sum=1+sum%10;      //Then The Sum Is The Sum Of The Digits
        temp[index]=sum+48;    //Return Changed Sum Value To TEmp Array
    }
    
    
    //Reset Indices For Next Calculations
    sum=0;//Reset Values For The Sum
    index=1;//Reset Value For The Index
    
    
    //Gather Sum Of Modified Card Number
    while(temp[index]!='\0'){//While Not At The End Of The Array
        sum+=temp[index-1]-48;//Get The Sum Of Each Element
        index++;//Increment The Index
    }
    
    //Calculate Check Digit From Sum
    check=(sum*9)%10;//Check == The Last Digit Of 9 Times The Sum
    
    
    //Assign Check Value To Make Card Valid
    card[index-1]=static_cast<char>(check+48);//Append Check To Card, Make Valid
    
    
    //Delete Dynamically Allocated Data
    delete [] temp;//Deallocate Temporary Card Pointer
    
    //Return Card To Main
    return card;//Return Pointer To Valid Card To Main
}


//*****************************************
//                                        *
//  Flip Random Digit Function            *
//                                        *
//*****************************************


void flipDig(char *card){
    //Declare And Initialize Variables
    short index=rand()%13;//Digit To Be Changed [0,12]
    short newVal=rand()%10;//New Value To Be Assigned To Card [0,9]
    
    //Change The Cards Value
    card[index]=static_cast<char>(newVal+48);//Assign Value To Array
    
}


//*****************************************
//                                        *
//  Luhn Card Validity Checker            *
//                                        *
//*****************************************


bool luhn(char *card){
    //Declare And Initialize Variables
    short sum=0,index=-1,check=0,i=0;//Sum For Check, Check Value, And 2 Indices
    char temp[19];//Temporary char Array To Calculate Check Digit
    
    
    
    //Copy Card Into Temporary Array
    while(card[i]!='\0'){//While Not At Tne End Of The Card, No Size Var Needed
        temp[i]=card[i];//Copy The Card Array Into The Temporary One
        i++;//Increment To Eventually Exit Loop
    }
    temp[i-1]='\0';//Replace Check Digit With Null To Make Calculating Easier
    
    
    
    //Set Index To The Last Digit Before The Check
    while(temp[index+1]!='\0')//While Not The End Of The Array
        index++;//Increment The Index
    
    
    
    //Modify The Temp Array According To The Luhn Algorithm
    for(;index>=0;index-=2){//For Every Other Number Starting From The End
        sum=(temp[index]-48)*2;//Sum Equals That Number Times 2
        if(sum>9)//If That Number Is Greater Than 10 (Cannot Be Held In A char)
            sum=1+sum%10;//Then The Number Is The Sum Of Its Digits
        temp[index]=sum+48;//Reassign The Modified Sum To The Temp Array
    }
    
    
    //Gather The Sum Of All Numbers
    sum=0;//Reset The Sum Running Total Var
    index=0;//Reset The Index Variable
    while(temp[index]!='\0'){//While Not At The End Of The Array
        sum+=temp[index]-48;//Each Element Is Added To The Sum
        index++;//Increment The Index
    }
    
    
    
    //Calculate The Check Digit
    check=(sum*9)%10;//Check == The Last Digit Of 9 Times The Sum
    
    
    
    //Return Boolean For Card Results
    if(check==card[i-1]-48)//If The Final Digit Of The Card Matches The Check
        return true;//Return True For A Valid Credit Card
    else            //Else
        return false;//Return False For An Invalid Credit Card Number

}
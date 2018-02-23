/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on February 14, 2018, 12:46 PM
 * Purpose: Luhn Algorithm Credit Card Number Verification
 */

//System Libraries
#include <iostream> //For Input/Output
#include <cstdlib>  //For atoi Function
#include <string>   //For Error Message String
using namespace std;



//Constants
const short SIZE=20;//Largest Size Of Credit Card, Constant


//Function Prototypes
void getCard(char []);//Gets The Card Number
bool calc(char []);//Calculates The Check Number




int main(){
    //Define Variables
    char card[SIZE];//Array For Credit Card Numbers
    bool status;
    
    
    //Initialize Variables
    status=false;//Initialize status as false
    for(int i=0;i<SIZE;i++)//For The Entire Card Array
        card[i]=0;        //Initialize Each Element To 0
    
    
    //Process Card Data
    getCard(card);//Fill Card Array
    
    status=calc(card);//Get The Check Number
    
    
    
    //Output Results
    if(status)
        cout<<"Valid Card Number";
    else
        cout<<"Invalid Card Number";
    
    
    //A Sebastian Production
    return 0;
}



//**********
//Functions*
//**********



void getCard(char card[]){//Fills Card Array With Proper Entry From User
    
    //Declare and Initialize Variables
    bool status=false;//Boolean Value To Continue Or End Try/Catch
    string error="Do Not Use Negative Numbers, Characters, Or Spaces";//Message
    
    
    //Get A Card Number From The User
    while(status==false){//While There Have Been Issues Or Not Entered Number
        
        //Try/Catch Block For Errors In Entry
        try{
            cout<<"Enter The Credit Card Number To Test It's Validity"
                    <<endl<<"Card: ";//Prompt User

            //Accept Values For Card Array
            cin.getline(card,SIZE);//Enter Card Number
            
            //Check For Non-Numerical Entry Using ASCII Values
            for(int i=0;card[i]!='\0';i++)//For The Length Of The Array
                if(card[i]<48||card[i]>57)//If Any Element Is Non-Numerical
                    throw error;//Throw The Error String, Leave Try Block
                
            status=true;//Set Status To True If No Errors Occurred
        }
        //Catch Error String If Thrown
        catch(string error){
            cout<<"Error "<<error<<endl;//Output Error Message
        }
    }
}





bool calc(char card[]){
    short sum=0,index=-1,check=0,i=0;
    char temp[SIZE];
    
    while(card[i]!='\0'){
        temp[i]=card[i];
        i++;
    }
    temp[i-1]='\0';
    
    
    
    while(temp[index+1]!='\0')
        index++;
    
    for(;index>=0;index-=2){
        sum=(temp[index]-48)*2;
        if(sum>9)
            sum=1+sum%10;
        temp[index]=sum+48;
    }
    
    sum=0;
    index=0;
    while(temp[index]!='\0'){
        sum+=temp[index]-48;
        index++;
    }
    
    check=(sum*9)%10;
    
    if(check==card[i-1]-48)
        return true;
    else
        return false;
}
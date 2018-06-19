/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on May 22, 2018, 5:59 PM
 * Purpose: Artificial Ignorance Program
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Global variables
bool invalid[10];
bool valid[10];
string hstry[15];
char cor1='\0';
char cor2='\0';
char cor3='\0';
char cor4='\0';
char prevRr='a';
bool pos1;
bool pos2;
bool pos3;
bool pos4;
bool fail1=false;
bool fail2=false;
bool fail3=false;
bool fail4=false;
bool try1=true;
bool try2=true;
bool try3=true;
bool try4=true;
int numCor=0;
int nGuess;         //number of guesses

//Function Prototypes
string AI(char,char);//AI Guesses Correct Code
bool eval(string,string,char &,char &);//Evaluates If Code Is Correct
string set();//Sets winning code
void reset(){
    try1=true;
    try2=true;
    try3=true;
    try4=true;
    fail1=false;
    fail2=false;
    fail3=false;
    fail4=false;
}



int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
   
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    bool win=false;
    
   
    //Initialize Values
    nGuess=1;
    code=set();
    guess=set();
    prevRr=rr=rw='0';
    
    for(int i=0;i<10;i++,nGuess++){
        //Display winning code
        cout<<"Winning Code: "<<code<<endl<<endl;

        //Output guess
        cout<<"Guess #"<<nGuess<<" "<<guess<<endl;

        //User evaluates code
        prevRr=rr;
        cout<<"Enter the number of digits in the correct position: ";
        cin>>rr;
        cout<<"Enter the number of correct digits in the wrong position: ";
        cin>>rw;
        hstry[i]=guess;
        eval(code,guess,rr,rw);
        guess=AI(rr,rw);
    }
    
    
    return 0;
}





//Computer guesses the winning string
string AI(char rr,char rw){
    //Declare variables
    string guess="0000";
    
    //If none are guessed
    if(rr=='0'&&rw=='0'){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
            if(invalid[guess[i]-'0']==true)
                i--;
        }
        return guess;
    }
    //If all numbers are known
    if(rr-'0'+rw-'0'==4){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
            if(valid[guess[i]-'0']==false)
                i--;
        }
    }    
    

    
    /*
     * CASE IF FIRST IS CORRECT
     */
    if(fail1==false&&rr>='1'&&pos1==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[0]>5+'0')
            guess[0]-=1;
        else
            guess[0]+=1;
            fail1=true;
            cout<<"In section 1"<<endl;
    }
    else if(rr<prevRr&&fail1==true&&pos1==false&&try1==true){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[0]<5+'0')
            guess[0]-=1;
        else
            guess[0]+=1;
        cor1=guess[0];
        pos1=true;
        cout<<"In section 2"<<endl;
        numCor++;
        reset();
        try1=false;
    }
    /*
     * CASE IF SECOND IS CORRECT
     */
    else if(rr>='1'&&fail2==false&&pos2==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[1]>5+'0')
            guess[1]-=1;
        else
            guess[1]+=1;
        fail2=true;
        try1=false;
        cout<<"In section 3"<<endl;
    }
    else if(rr<prevRr&&fail2==true&&pos2==false&&try2==true){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[1]<5+'0')
            guess[1]-=1;
        else
            guess[1]+=1;
        cor2=guess[1];
        pos2=true;
        cout<<"In section 4"<<endl;
        numCor++;
        reset();
        try2=false;
    }
    /*
     * CASE IF THIRD IS CORRECT
     */
    else if(fail3==false&&rr>='1'&&pos3==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[2]>5+'0')
            guess[2]-=1;
        else
            guess[2]+=1;
            fail3=true;
            try2=false;
            cout<<"In section 5"<<endl;
    }
    else if(rr<prevRr&&fail3==true&&pos3==false&&try3==true){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[2]<5+'0')
            guess[2]-=1;
        else
            guess[2]+=1;
        cor3=guess[2];
        pos3=true;
        cout<<"In section 6"<<endl;
        numCor++;
        reset();
        try3==false;
    }
    /*
     * CASE IF FOURTH IS CORRECT
     */
    else if(fail4==false&&rr>='1'&&pos4==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[3]>5+'0')
            guess[3]-=1;
        else
            guess[3]+=1;
            fail4=true;
            try3=false;
            cout<<"In section 5"<<endl;
    }
    else if(rr<prevRr&&fail4==true&&pos4==false&&try4==true){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[3]<5+'0')
            guess[3]-=1;
        else
            guess[3]+=1;
        cor4=guess[3];
        pos4=true;
        cout<<"In section 8"<<endl;
        numCor++;
        reset();
        try4=false;
    }
    else if(rr=='0'){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
            if(invalid[guess[i]-'0']==true)
                i--;
        }
        cout<<"DEFAULT SECTION"<<endl;
    }
    else
        cout<<"Logic line 1 ended"<<endl;
        
    
    
    
    //Assign correct values to guess
    if(pos1==true)
        guess[0]=cor1;
    if(pos2==true)
        guess[1]=cor2;
    if(pos3==true)
        guess[2]=cor3;
    if(pos4==true)
        guess[3]=cor4;
    
    
    
    //Return guess
    return guess;
}

//Evaluates the winning string
bool eval(string code,string guess,char &rr,char &rw){
    if(rr=='0'&&rw=='0'){
        for(int i=0;i<guess.length();i++){
            switch(guess[i]-'0'){
                case 0:invalid[0]=true;break;
                case 1:invalid[1]=true;break;
                case 2:invalid[2]=true;break;
                case 3:invalid[3]=true;break;
                case 4:invalid[4]=true;break;
                case 5:invalid[5]=true;break;
                case 6:invalid[6]=true;break;
                case 7:invalid[7]=true;break;
                case 8:invalid[8]=true;break;
                case 9:invalid[9]=true;break;
            }
        }
    }
    if(rr-'0'+rw-'0'==4){
        for(int i=0;i<guess.length();i++){
            switch(guess[i]-'0'){
                case 0:valid[0]=true;break;
                case 1:valid[1]=true;break;
                case 2:valid[2]=true;break;
                case 3:valid[3]=true;break;
                case 4:valid[4]=true;break;
                case 5:valid[5]=true;break;
                case 6:valid[6]=true;break;
                case 7:valid[7]=true;break;
                case 8:valid[8]=true;break;
                case 9:valid[9]=true;break;
            }
        }
    }
    
    
    
    
    
    
    
    
    //Return win value
    if(rr==4)
        return true;
    else
        return false;
}

//The function for setting the winning string
string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}
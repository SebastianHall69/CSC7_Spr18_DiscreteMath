


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


//Global Variables
bool valid[10];
string hstry[40];
char rrHist[40];
int nGuess;
int numCor=0;
bool rPos[4];
bool tryPos[4];
bool skip[4];
char key[4];


//Functions
string AI(char,char);//AI Guesses Correct Code
bool eval(string,string,char &,char &);//Evaluates If Code Is Correct
string set();//Sets winning code
void reset(){
    for(int i=0;i<4;i++){
        tryPos[i]=true;
        skip[i]=false;
    }
}



int main(){
    srand(time(0));
    //Declare variables
    string code="",guess="";
    char rr,rw='0';
    bool win=false;
    
    //Initialize variables
    nGuess=0;
    code=set();
    guess=set();
    for(int i=0;i<4;i++){
        tryPos[i]=true;
        key[i]='\0';
    }
    for(int i=0;i<10;i++)
        valid[i]=true;
    
    
    do{
        hstry[nGuess]=guess;
        cout<<"Round "<<++nGuess<<endl;
        win=eval(code,guess,rr,rw);
        rrHist[nGuess-1]=rr;
        guess=AI(rr,rw);
        
        
        
    }while(win==false);
    
    
    //Exit
    cout<<"Successfully Completed"<<endl;
    
    return 0;
}



string AI(char rr,char rw){
    string guess="0000";
    
    /*
     * CASE IF FIRST IS CORRECT
     */
    
    if(rr>='1'&&rPos[0]==false&&tryPos[0]==true&&skip[0]==false){
        for(int i=0;i<guess.length();i++){
                guess[i]=hstry[nGuess-1][i];
            }
        if(rr-'0'==numCor){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
        if(valid[guess[i]-'0']==false)
            i--;
        }
        for(int i=0;i<4;i++)
            if(rPos[i])
                guess[i]=key[i];
        return guess;
        }
            if(guess[0]>5+'0')
            guess[0]-=1;
        else
            guess[0]+=1;
        tryPos[0]=false;
    }
    else if(rr>rrHist[nGuess-2]&&rPos[0]==false){
        rPos[0]=true;
        key[0]=guess[0];
        
    }
    else if(rr<rrHist[nGuess-2]&&tryPos[0]==false&&rPos[0]==false&&skip[0]==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[0]<5+'0')
            guess[0]-=1;
        else
            guess[0]+=1;
        rPos[0]=true;
        numCor++;
        key[0]=guess[0];
        reset();
    }
    /*
     * CASE IF SECOND IS CORRECT
     */
    else if(rr>='1'&&rPos[1]==false&&tryPos[1]==true&&skip[1]==false){
        for(int i=0;i<guess.length();i++){
                guess[i]=hstry[nGuess-1][i];
            }
        if(rr-'0'==numCor){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
        if(valid[guess[i]-'0']==false)
            i--;
        }
        for(int i=0;i<4;i++)
            if(rPos[i])
                guess[i]=key[i];
        return guess;
    }
        if(guess[1]>5+'0')
            guess[1]-=1;
        else
            guess[1]+=1;
        tryPos[1]=false;
        skip[0]=true;
    }
    else if(rr>rrHist[nGuess-2]&&rPos[1]==false){
        rPos[1]=true;
        key[1]=guess[1];
        
    }
    else if(rr<rrHist[nGuess-2]&&tryPos[1]==false&&rPos[1]==false&&skip[1]==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[1]<5+'0')
            guess[1]-=1;
        else
            guess[1]+=1;
        rPos[1]=true;
        numCor++;
        key[1]=guess[1];
        reset();
    }
    /*
     * CASE IF THIRD IS CORRECT
     */
    else if(rr>='1'&&rPos[2]==false&&tryPos[2]==true&&skip[2]==false){
        for(int i=0;i<guess.length();i++){
                guess[i]=hstry[nGuess-1][i];
            }
        if(rr-'0'==numCor){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
        if(valid[guess[i]-'0']==false)
            i--;
        }
        for(int i=0;i<4;i++)
            if(rPos[i])
                guess[i]=key[i];
        return guess;
    }
        if(guess[2]>5+'0')
            guess[2]-=1;
        else
            guess[2]+=1;
        tryPos[2]=false;
        skip[1]=true;
    }
    else if(rr>rrHist[nGuess-2]&&rPos[2]==false){
        rPos[2]=true;
        key[2]=guess[2];
        
    }
    else if(rr<rrHist[nGuess-2]&&tryPos[2]==false&&rPos[2]==false&&skip[2]==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[2]<5+'0')
            guess[2]-=1;
        else
            guess[2]+=1;
        rPos[2]=true;
        numCor++;
        key[2]=guess[2];
        reset();
    }
    /*
     * CASE IF FOURTH IS CORRECT
     */
    else if(rr>='1'&&rPos[3]==false&&tryPos[3]==true){
        for(int i=0;i<guess.length();i++){
                guess[i]=hstry[nGuess-1][i];
            }
        if(rr-'0'==numCor){
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
        if(valid[guess[i]-'0']==false)
            i--;
        }
        for(int i=0;i<4;i++)
            if(rPos[i])
                guess[i]=key[i];
        return guess;
    }
            if(guess[3]>5+'0')
            guess[3]-=1;
        else
            guess[3]+=1;
        tryPos[3]=false;
        skip[2]=true;
    }
    else if(rr>rrHist[nGuess-2]&&rPos[3]==false){
        rPos[3]=true;
        key[3]=guess[3];
        
    }
    else if(rr<rrHist[nGuess-2]&&tryPos[3]==false&&rPos[3]==false){
        for(int i=0;i<guess.length();i++){
            guess[i]=hstry[nGuess-1][i];
        }
        if(guess[3]<5+'0')
            guess[3]-=1;
        else
            guess[3]+=1;
        rPos[3]=true;
        numCor++;
        key[3]=guess[3];
        reset();
    } 
    else{
        for(int i=0;i<guess.length();i++){
            guess[i]=rand()%10+'0';
        if(valid[guess[i]-'0']==false)
            i--;
        }
    }
    for(int i=0;i<4;i++)
        if(rPos[i]){
            guess[i]=key[i];
        }
    return guess;   
}

bool eval(string code,string guess,char &rr,char &rw){
    cout<<"Winning Code:   "<<code<<endl;
    cout<<"Computer Guess: "<<guess<<endl<<endl;
    cout<<"Number Of Digits In The Correct Position: ";
    cin>>rr;
    cout<<"Correct Digits In Wrong Position: ";
    cin>>rw;
    cout<<endl<<endl<<endl;
    
    if(rr=='0'&&rw=='0'){
        for(int i=0;i<guess.length();i++){
            valid[guess[i]-'0']=false;
        }
    }
    if(rr-'0'+rw-'0'== 4){
        for(int i=0;i<10;i++)
            valid[i]=false;
        for(int i=0;i<guess.length();i++)
            valid[guess[i]-'0']=true;    
   }
    if(code==guess||rr-'0'==4){
        return true;
    }
}

//The function for setting the winning string
string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}
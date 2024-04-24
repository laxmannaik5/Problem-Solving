#include<iostream>
using namespace std;

void generateBrackets(string output, int n, int open, int close, int i){
    //base case
    if(i==2*n){
        cout<<output<<endl;
        return;
    }
    //open
    if(open<n){
        //output += '(';
        generateBrackets(output+'(',n,open+1,close,i+1);
        //output.pop_back();
    }

    //closing
    if(close<open){
        output += ')';
        generateBrackets(output,n,open,close+1,i+1);
        output.pop_back();
    }
}

int main(){
    string output;
    int n;
    cin>>n;
    generateBrackets(output,n,0,0,0);

    return 0;
}
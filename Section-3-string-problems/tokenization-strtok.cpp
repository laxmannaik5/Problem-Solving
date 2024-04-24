#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    char input[1000];
    cin.getline(input,1000);

    //strtok()
    //it works on character arrays
    // cout<<strtok(input," ")<<endl;

    // cout<<strtok(NULL," ")<<endl;//internally maintains the state of the string you passed in the last function call, static variable
    // cout<<strtok(NULL," ")<<endl;
    // cout<<strtok(NULL," ")<<endl;

    char *token = strtok(input," ");

    while(token!=NULL){
        cout<<token<<endl;
        token = strtok(NULL," ");
    }
}
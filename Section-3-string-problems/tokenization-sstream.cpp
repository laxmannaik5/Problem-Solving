#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;

int main(){

    string input;
    getline(cin, input);
    //"This is a sunny day"

    //create a string stream object
    stringstream ss(input);

    //>> and << operator
    string token;
    vector<string> tokens;
    while(getline(ss,token,' ')){
        tokens.push_back(token);
    }

    //print all tokens
    for(auto token: tokens){
        cout<<token<<",";
    }


    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    // char s[1000] = {'a','1','b','c','\0'};

    // string s = "hello world"; //Dynamic array

    // string s;

    // getline(cin, s, '.');

    // for(char ch: s){
    //     cout<<ch<<",";
    // }

    // cout<<s<<endl;

    string s;

    int n=5;
    vector<string> sarr;
    string temp;

    while(n--){
        getline(cin,temp);
        sarr.push_back(temp);
    }
    for(string x: sarr){
        cout<<x<<","<<endl;
    }
}
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkRedundant(string str){
    //complete
    stack<char> s;
    for(char ch: str){
        if(ch!=')'){
            s.push(ch);//a,b,+,-,(...
        }else{
            //')'
            bool operator_found = false;
            while(!s.empty() and s.top()!='('){
                char top = s.top();
                if(top=='+' or top=='-' or top=='*' or top=='/'){
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();//pop the opening bracket after loop is over
            if(operator_found==false){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string str = "((a+b)+c) * (c+d)";
    if(checkRedundant(str)){
        cout<<"Contains Redundant parenthesis";
    }else{
        cout<<"Doesn't contain redundant parenthesis";
    }
    return 0;
}
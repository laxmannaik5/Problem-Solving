#include<iostream>
using namespace std;

char *mystrtok(char *str, char delim){

}

int main(){
    char s[1000];
    cin.getline(s,1000);

    //strtok()
    char *token = mystrtok(s, ' ');

    while(token!=NULL){
        cout<<token<<endl;
        token = mystrtok(NULL, ' ');
    }
    return 0;
}
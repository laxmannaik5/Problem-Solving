#include<iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = (1<<i);
    return (n & mask) ? 1 : 0;

}

void setIthBit(int &n, int i){
    int mask = (1<<i);
    n= n|mask;
}

void clearIthBit(int &n, int i){
    int mask = ~(1<<i);
    n = n & mask;
}

void updateIthBit(int &n, int i, int v){
    clearIthBit(n,i);
    int mask = (v<<i);
    n = n | mask; //sets the right value
}

void clearLastIBit(int &n, int i){
    int mask = (-1<<i);
    n = n & mask;
}

int main(){
    int n=15;
    int p=2;
    //cin>>p;
    //cout<<getIthBit(n,p)<<endl;
    //setIthBit(n,p);
    //clearIthBit(n,p);
    //updateIthBit(n,p,1);
    clearLastIBit(n,p);
    cout<<n<<endl;

    return 0;
}
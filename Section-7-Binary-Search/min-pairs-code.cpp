#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2){

    //Sort the array
    sort(a2.begin(), a2.end());

    int p1,p2;
    int diff = INT_MAX;

    //iterate over 1 array and look for closest element in the second array
    for(auto x:a1){
        auto lb = lower_bound(a2.begin(),a2.end(),x)-a2.begin(); //Here lower_bound gives the element next >= element.

    //left
    if(lb>=1 and x-a2[lb-1] < diff){
        diff = x-a2[lb-1];
        p2 = x;
        p1 = a2[lb-1];
    }

    //greater / right
    if(lb!=a2.size() and a2[lb]-x < diff){
        diff = a2[lb] - x;
        p2 = a2[lb];
        p1 = x;
    }
    }
    cout<<"Min Pairs "<<p1<<" and "<<p2<<endl;
    return;
}

int main(){
    vector<int> a1 = {-1, 5, 10, 20, 3};
    vector<int> a2 = {26,134,135,15,17};
    min_pair(a1,a2);

    return 0;
}
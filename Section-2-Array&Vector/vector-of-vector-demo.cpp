#include<iostream>
#include<vector>
using namespace std;

int main(){

    //2D vector
    vector<vector<int>> arr = {{1,2,3},{3,4,5},{12,4,5,6},{1,9}}; //each row can have different column

    arr[0][0] +=10;  //update

    for(int i=0;i<arr.size();i++){   //arr.size() gives number of rows
        for(int number: arr[i]){
            cout<<number<<",";
        }
        cout<<endl;
    }

    return 0;
}
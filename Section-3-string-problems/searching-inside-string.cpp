#include<iostream>
#include<string>
using namespace std;

int main(){
    string paragraph = "We are learning about STL strings.STL string class is quite powerful";

    string word;
    getline(cin,word);

    //find function

    // cout<<paragraph.find(word)<<endl;
    int index = paragraph.find(word);

    if(index==-1){
        cout<<"String not found"<<endl;
    }

    if(index!=-1){
        cout<<"first occ "<<index<<endl;
    }

    index = paragraph.find(word, index+1);
    
    if(index!=-1){
        cout<<"second occ "<<index;
    }

    return 0;
}
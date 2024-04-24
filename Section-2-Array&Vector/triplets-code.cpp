#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int targetSum){
    //Logic
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result1;

    //Pick every a[i] and solve pairSum for remaining part.
    for(int i=0;i<=n-3;i++){
        int j = i+1;
        int k = n-1;

        //two pointer approach
        while(j<k){
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];
            if(current_sum==targetSum){
                result1.push_back({arr[i], arr[j], arr[k]});
            }
            else if(current_sum > targetSum){
                k--;
            }
            else{
                j++;
            }
        }

    } 
    return result1;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S = 18;
    auto result = triplets(arr, S);

    for(auto v: result){
        for(auto no: v){
            cout<<no<<",";
        }
        cout<<endl;
    }

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    bool flags[INT_MAX]={false};
    flags[0]=true;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            flags[nums[i]]=true;
        }
    }
    for(int i=0;i<INT_MAX;i++){
        if(flags[i]==false){
            return i;
        }
    }
    return 0;
}

int main(){
    vector<int> nums={2147483647};
    int result = firstMissingPositive(nums);
    cout<<result<<endl;
    return 0;
}
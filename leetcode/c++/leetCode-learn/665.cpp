#include<iostream>
#include<vector>

using namespace std;


bool checkPossibility(vector<int>& nums) {
    int flag=0;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            flag++;
            if(i>0 && nums[i-1]>nums[i+1]){
                return false;
            }
        }
    }
    if(flag<=1){
        return true;
    }
    return false;
}

int main(){
    vector<int> nums={3,4,2,3};
    bool result = checkPossibility(nums);
    cout<<result<<endl;
    return 0;
}
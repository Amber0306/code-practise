#include<iostream>
#include<vector>

using namespace std;



int thirdMax(vector<int>& nums) {
    int firstMax = NULL ;
    int secondMax=NULL;
    int thirdMax=NULL;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>firstMax){
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        }else if(nums[i]<firstMax && nums[i]>secondMax){
            thirdMax = secondMax;
            secondMax = nums[i];
        }else if(nums[i]<secondMax && nums[i]>thirdMax){
            thirdMax = nums[i];
        }else if(nums[i]<thirdMax){
            continue;
        }else{
            continue;
        }
    }
    if(thirdMax==NULL){
        return firstMax;
    }else{
        return thirdMax;
    }
    //return thirdMax;
}

int main(){
    cout<<"hello world"<<endl;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-2147483648);
    
    int result = thirdMax(nums);
    cout<<result<<endl;
    return 0;
}
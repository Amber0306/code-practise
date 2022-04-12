#include<iostream>
#include<vector>

using namespace std;



int maximumProduct(vector<int>& nums) {
    int firstMax, secondMax, thirdMax = INT_MIN;
    int firstMin, secondMin = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > firstMax){
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        }else if(nums[i] > secondMax){
            thirdMax = secondMax;
            secondMax = nums[i];
        }else if(nums[i] > thirdMax){
            thirdMax = nums[i];
        }

        if(nums[i]<firstMin){
            secondMin= firstMin;
            firstMin = nums[i];
        }else if(nums[i]<secondMin){
            secondMin=nums[i];
        }
    }
    return max(firstMax*secondMax*thirdMax, firstMax*secondMin*firstMin);
    
}

int main(){
    cout<<"hello world"<<endl;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    int result = maximumProduct(nums);
    cout<<result<<endl;
    return 0;
}
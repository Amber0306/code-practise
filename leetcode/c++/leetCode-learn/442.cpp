#include<iostream>
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        int index = abs(nums[i]);
        int value  = nums[index-1];
        if(value<0){
            //该index数值已存在
            result.push_back(index);
            continue;
        }
        nums[index-1] = -value;
    }
    return result;
}

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int>result = findDuplicates(nums);
    vector<int>::iterator itr=result.begin();
    for(;itr!=result.end();itr++){
        cout<<*itr<<endl;
    }
    return 0;
}
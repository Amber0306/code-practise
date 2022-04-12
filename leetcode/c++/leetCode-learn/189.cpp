#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    //
    int n=nums.size();
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        int index=(i+k)%n;
        temp[index]=nums[i];
    }
    nums=temp;
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    rotate(nums,3);
    return 0;
}
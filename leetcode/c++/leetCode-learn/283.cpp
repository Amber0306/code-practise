#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    if(n<=1){
        return;
    }
    int i=0;
    while(i<n){
        if(nums[i]==0){
            int j=i;
            while(j<n-1){
                nums[j]=nums[j+1];
                j++;
            }
            nums.back()=0;
        }
        if(nums[i]!=0){
            i++;
        }
    }
    // for(int i=0;i<n;i++){
    //     if(nums[i]==0){
    //         int j=i;
    //         while(j<n-1){
    //             nums[j]=nums[j+1];
    //             j++;
    //         }
    //         nums.back()=0;
    //     }
    // }
}

int main(){
    vector<int>nums={0,0,1};
    moveZeroes(nums);
    vector<int>::iterator itr=nums.begin();
    while(itr!=nums.end()){
        cout<<*itr<<'\t';
        itr++;
    }
    
    return 0;
}
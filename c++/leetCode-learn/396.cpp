#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n=nums.size();
    int maxF=INT_MIN;
    vector<int> temp;
    for(int i=0;i<n;i++){
        int F=0;
        //求出当前的F
        temp=nums;
        //旋转i个单位
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+i);
        reverse(temp.begin()+i,temp.end());
        //求F
        for(int j=0;j<n;j++){
            F+=j*temp[j];
        }
        //修改最终的F
        if(F>maxF){
            maxF = F;
        }
    }
    return maxF;
}

int main(){
    vector<int> nums={4,3,2,6};
    int result = maxRotateFunction(nums);
    return 0;
}
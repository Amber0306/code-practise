#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minMoves(vector<int>& nums) {
    int time=0;
    //int flag;
    int max;
    int maxIndex=-1;
    
    while(true){
        //flag=true;
        max=INT_MIN;
        vector<int> compare(nums.size(),nums[0]);
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]!=nums[i+1]){
        //         flag=false;
        //         break;
        //     }
        // }
        if(compare==nums){
            return time;
        }
        time++;
        //升序排序
        //sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
                maxIndex=i;
            }
            nums[i]++;
        }
        nums[maxIndex]--;
    }
    return -1;
    
}

int main(){
    vector<int> nums={1,2,3};
    int result = minMoves(nums);
    cout<<result<<endl;
    system("pause");
    return 0;
}
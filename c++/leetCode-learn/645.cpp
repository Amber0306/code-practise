#include<iostream>
#include<vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<bool> flags(nums.size()+1);
    int lose;
    int repeat;
    
    for(int i=0;i<nums.size();i++){
        int index = nums[i];
        if(flags[index]==false){
            flags[index]=true;
        }else{
            repeat=index;
        }
    }

    for(int i=1;i<flags.size();i++){
        if(flags[i]==false){
            lose=i;
        }
    }

    vector<int>result;
    result.push_back(repeat);
    result.push_back(lose);
    return result;

}

int main(){
    cout<<"hello world"<<endl;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);

    vector<int> result;
    result = findErrorNums(nums);
    for(vector<int>::iterator m = result.begin();m!=result.end();m++){
        cout<<*m<<endl;
    }
    system("pause");
    return 1;
}
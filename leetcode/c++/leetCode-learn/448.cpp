#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        int num = nums[i];
        int index = abs(num)-1;
        nums[index]=-abs(nums[index]);
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            result.push_back(i+1);
        }
    }
    return result;
}

int main()
{
    cout << "hello world" << endl;
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> result = findDisappearedNumbers(nums);
    for(vector<int>::iterator m = result.begin();m!=result.end();m++){
        cout<<*m<<endl;
    }
    system("pause");
    return 1;
}
#include <iostream>
#include <vector>
using namespace std;

int findShortestSubArray(vector<int> &nums)
{
    vector<vector<int>> numsRank(50001);
    vector<bool> numsFlag(50001);
    for(int i=0;i<nums.size();i++){
        int index = nums[i];
        if(numsFlag[index]==false){
            vector<int> temp;
            temp.push_back(i);
            numsRank[index] = temp;
            numsFlag[index]=true;
        }else{
            numsRank[index].push_back(i);
        }
    }

    int minLeng= INT_MAX;
    int maxSize=0;
    vector<vector<int>>::iterator itr = numsRank.begin();
    while(itr!=numsRank.end()){
        int temp=(*itr).size();
        int begin,end;
        if(temp>maxSize){
            maxSize = temp;
            begin = (*itr).at(0);
            end = (*itr).back();
            minLeng = end-begin+1;
        }else if(temp==maxSize){
            begin = (*itr).at(0);
            end = (*itr).back();
            int templen=end-begin+1;
            if(templen<minLeng){
                minLeng=templen;
            }
        }
        itr++;
    }
    return minLeng;
}

int main()
{
    cout << "hello world" << endl;
    vector<int> nums = {1,2,2,3,1,4,2};

    int result = findShortestSubArray(nums);
    cout << result << endl;
    system("pause");
    return 1;
}
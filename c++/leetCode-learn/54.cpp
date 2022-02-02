#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int num=m*n;
        vector<int> result;
        int toward=1;//1右, 2下，3左，4上
        
        int k=0; int i=0;int j=0;
        while(k<num){
            result.push_back(matrix[i][j]);
            matrix[i][j]=-200;
            switch (toward)
                {
                case 1:
                    //往右走，看看右边是否还有，右边还有，向右走
                    if(j+1<n&&matrix[i][j+1]>-200){
                        j++;
                    }else if(i+1<m&&matrix[i+1][j]>-200){
                        //右边没有，看下面有没有，下边还有，往下走
                        toward=2;
                        i++;
                    }else{
                         //右边下边都没有，结束
                        return result;
                    }
                    break;
                case 2:
                    //往下走，看看下边是否还有，下边还有，向下走
                    if(i+1<m&&matrix[i+1][j]>-200){
                        i++;
                    }else if(j-1>=0&&matrix[i][j-1]>-200){
                        //下边没有，看左面有没有，左边还有，往左走
                        toward=3;
                        j--;
                    }else{
                         //下边左边都没有，结束
                        return result;
                    }
                    break;
                case 3:
                     //往左走，看看左边是否还有，左边还有，向左走
                    if(j-1>=0&&matrix[i][j-1]>-200){
                        j--;
                    }else if(i-1>=0&&matrix[i-1][j]>-200){
                        //左边没有，看上面有没有，上边还有，往上走
                        toward=4;
                        i--;
                    }else{
                         //左边上边都没有，结束
                        return result;
                    }
                    break;
                case 4:
                    //往上走，看看上边是否还有，上边还有，向上走
                    if(i-1>=0&&matrix[i-1][j]>-200){
                        i--;
                    }else if(j+1<n&&matrix[i][j+1]>-200){
                        //上边没有，看右面有没有，右边还有，往右走
                        toward=1;
                        j++;
                    }else{
                         //上边右边都没有，结束
                        return result;
                    }
                    break;
                default:
                    return result;
                }
            k++;
        }
        return result;
    }
};

int main(){
    Solution* solu = new Solution();
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = solu->spiralOrder(matrix);
    return 0;
}
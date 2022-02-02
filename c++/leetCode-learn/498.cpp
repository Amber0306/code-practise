#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0,j=0,k=0;
        int m=mat.size();
        int n=mat[0].size();
        int num=m*n;
        vector<int> result(num);
        int toward=0;//0右上，1左下
        while(k<num){
            result[k]=mat[i][j];
            if(toward==0){
                //方向右上，看右上有无
                if(i-1>=0&&j+1<n){
                    i--;j++;
                }else if(i>=0&&j+1<n){
                    //右上无，右侧有
                    //k++;
                    j++;
                    //result[k]=mat[i][j];
                    toward=1;
                }else if(i+1<m&&j<n){
                    //右侧无，右上无，往下走
                    i++;
                    toward=1;
                }
            }else if(toward==1){
                //方向左下，看看左下有无
                if(i+1<m&&j-1>=0){
                    i++;j--;
                }else if(i+1<m&&j<n){
                    //左侧无，左下无，往下走
                    i++;
                    toward=0;
                }else if(i>=0&&j+1<n){
                    //左下无，右侧有
                    //k++;
                    j++;
                    //result[k]=mat[i][j];
                    toward=0;
                }
            }else{
                return result;
            }
            k++;
        }
        return result;
    }
};

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    Solution* solu=new Solution();
    vector<int> result = solu->findDiagonalOrder(mat);
    return 0;
}
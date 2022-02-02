#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int zeroM[m]={0};
        int zeroN[n]={0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroM[i]=1;
                    zeroN[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(zeroM[i]==1){
                //该行需要置零
                for(int k=0;k<n;k++){
                    matrix[i][k]=0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(zeroN[j]==1){
                //该列需要置零
                for(int k=0;k<m;k++){
                    matrix[k][j]=0;
                }
            }
        }
    }
};

int main(){
    Solution* solu = new Solution();
    vector<vector<int>>matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solu->setZeroes(matrix);
    return 0;
}
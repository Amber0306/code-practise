#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(m*n!=r*c){
            return mat;
        }
        vector<vector<int>> result(r, vector<int>(c,0));
        int num=r*c;
        int i1=0,j1=0,i2=0,j2=0;
        for(int k=0;k<num;k++){
            i1=k/n;
            j1=k%n;
            i2=k/c;
            j2=k%c;
            result[i2][j2]=mat[i1][j1];
        }
        return result;
    }
};

int main(){
    vector<vector<int>> mat={{1,2},{3,4}};
    Solution * solu=new Solution();
    vector<vector<int>> result= solu->matrixReshape(mat,1,4);
    return 0;
}
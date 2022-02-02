#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>result(n);

        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                result[j].push_back(matrix[i][j]);
            }
        }
        matrix=result;
    }
};

int main(){
    Solution* solu =new Solution();
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    solu->rotate(matrix);
    return 0;
}
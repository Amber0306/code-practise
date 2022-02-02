#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int row = M.size();
    vector<vector<int>> result(row);

    for(int i=0;i<row;i++){
        int col = M[i].size();
        result[i].resize(col);

        for(int j=0;j<col;j++){
            int num=0;
            if(i==0){
                if(j==0){
                    int sum = M[i][j]+M[i][j+1]+M[i+1][j]+M[i+1][j+1];
                    result[i][j]=sum/4;
                }else if(j==(col-1)){
                    int sum = M[i][j]+M[i][j-1]+M[i+1][j]+M[i+1][j-1];
                    result[i][j]=sum/4;
                }else{
                    int sum =M[i][j-1]+M[i][j]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1];
                    result[i][j]=sum/6;
                }
            }else if(i==(row-1)){
                if(j==0){
                    int sum = M[i][j]+M[i][j+1]+M[i-1][j]+M[i-1][j+1];
                    result[i][j]=sum/4;
                }else if(j==(col-1)){
                    int sum = M[i][j]+M[i][j-1]+M[i-1][j]+M[i-1][j-1];
                    result[i][j]=sum/4;
                }else{
                    int sum = M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j]+M[i][j+1];
                    result[i][j]=sum/6;
                }
            }else{
                int sum = M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1];
                result[i][j]=sum/9;
            }
        }
    }
    return M;
}

int main(){
    vector<vector<int>> M = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> result  = imageSmoother(M);
    return 0;
}
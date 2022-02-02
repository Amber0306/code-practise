#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        if(m<1||n<1){
            return;
        }else if(m==1&&n==1){
            board[0][0]=0;
            return;
        }else if(m==1||n==1){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    board[i][j]=0;
                }
            }
            return;
        }
        vector<vector<int>> result(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //检查有周围有几个活的细胞
                //int num=checkLife(i,j,board);
                int num=0;
                if(i==0&&j==0){
                    num=board[i][j+1]+board[i+1][j]+board[i+1][j+1];
                }else if(i==0&&j>0&&j<n-1){
                    num=board[i][j-1]+board[i][j+1]+board[i+1][j-1]+board[i+1][j]+board[i+1][j+1];
                }else if(i==0&&j==n-1){
                    num=board[i][j-1]+board[i+1][j-1]+board[i+1][j];
                }else if(i>0&&i<m-1&&j==0){
                    num=board[i-1][j]+board[i-1][j+1]+board[i][j+1]+board[i+1][j]+board[i+1][j+1];
                }else if(i>0&&i<m-1&&j==n-1){
                    num=board[i-1][j-1]+board[i-1][j]+board[i][j-1]+board[i+1][j-1]+board[i+1][j];
                }else if(i==m-1&&j==0){
                    num=board[i-1][j]+board[i-1][j+1]+board[i][j+1];
                }else if(i==m-1&&j>0&&j<n-1){
                    num=board[i-1][j-1]+board[i][j-1]+board[i-1][j]+board[i-1][j+1]+board[i][j+1];
                }else if(i==m-1&&j==n-1){
                    num=board[i-1][j-1]+board[i][j-1]+board[i-1][j];
                }else{
                    num=board[i-1][j-1]+board[i-1][j]+board[i-1][j+1]+board[i][j-1]+board[i][j+1]+board[i+1][j-1]+board[i+1][j]+board[i+1][j+1];
                }
                /**************************/
                int value=board[i][j];
                //本身是活的还是死的
                if(value==0){
                    if(num==3){
                        result[i][j]=1;
                    }else{
                        result[i][j]=0;
                    }
                }else if(value==1){
                    if(num==0 ||num==1||num>3){
                        result[i][j]=0;
                    }else if(num==2||num==3){
                        result[i][j]=1;
                    }else{
                        return;
                    }
                }else{
                    return;
                }
            }
        }
        board=result;
    }
};

int main(){
    Solution* solu = new Solution();
    vector<vector<int>> board = {{1,1}};
    solu->gameOfLife(board);
    return 0;
}
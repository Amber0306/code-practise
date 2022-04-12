#include<iostream>
#include<vector>

using namespace std;


int maxCount(int m, int n, vector<vector<int>>& ops) {
    //初始化
    vector<vector<int>> matrix(m,vector<int>(n,0));
    int stepNum=ops.size();
    for(int step=0;step<stepNum;step++){
        int row=ops[step][0];
        int col=ops[step][1];
        //单次操作
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]++;
            }
        }
    }
    //找出最大的数，并计算重复率
    int max=-1;
    int num=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int value=matrix[i][j];
            if(value>max){
                max=value;
                num=1;
            }else if(value==max){
                num++;
            }else{
                continue;
            }
        }
    }
    
    return num;
}

int main(){
    int m=3,n=3;
    vector<vector<int>> ops={{2,2},{3,3}};
    int result = maxCount(m,n,ops);
    return 0;
}
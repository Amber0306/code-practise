#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> rects(numRows);
    if(numRows==0){
        return rects;
    }else if(numRows==1){
        rects[0].push_back(1);
        return rects;
    }else if(numRows==2){
        rects[0].push_back(1);
        rects[1].push_back(1);
        rects[1].push_back(1);
        return rects;
    }
    rects[0].push_back(1);
    rects[1].push_back(1);
    rects[1].push_back(1);
    for(int i=2;i<numRows;i++){
        rects[i].push_back(1);
        int temp;
        for(int j=1;j<i;j++){
            temp=rects[i-1][j-1]+rects[i-1][j];
            rects[i].push_back(temp);
        }
        rects[i].push_back(1);
    }
    return rects;
}

int main(){
    vector<vector<int>> result = generate(5);
    return 0;
}
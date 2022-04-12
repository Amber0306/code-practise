#include<iostream>
#include<vector>
using namespace std;

vector<int> generate(int rowIndex) {
    rowIndex++;
    vector<vector<int>> rects(rowIndex);
    if(rowIndex==0){
        return rects[0];
    }else if(rowIndex==1){
        rects[0].push_back(1);
        return rects[0];
    }else if(rowIndex==2){
        rects[0].push_back(1);
        rects[1].push_back(1);
        rects[1].push_back(1);
        return rects[1];
    }
    rects[0].push_back(1);
    rects[1].push_back(1);
    rects[1].push_back(1);
    for(int i=2;i<rowIndex;i++){
        rects[i].push_back(1);
        int temp;
        for(int j=1;j<i;j++){
            temp=rects[i-1][j-1]+rects[i-1][j];
            rects[i].push_back(temp);
        }
        rects[i].push_back(1);
    }
    return rects[rowIndex-1];
}

int main(){
    vector<int> result = generate(3);
    return 0;
}
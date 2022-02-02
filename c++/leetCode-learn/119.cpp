#include<iostream>
#include<vector>

using namespace std;

int getF(int num){
    if(num==0||num==1){
        return 1;
    }else{
        return num*getF(num-1);
    }
}
vector<int> getRow(int rowIndex) {
    vector<int> rowNum(rowIndex+1);
    int n=rowIndex+1;
    int nT=getF(rowIndex);
    for(int i=0;i<n;i++){
        int mT=getF(i);
        int mnT=getF(rowIndex-i);
        int value=nT/(mT*mnT);
        rowNum[i]=value;
    }
    return rowNum;
}

int main(){
    vector<int> result = getRow(4);
    return 0;
}
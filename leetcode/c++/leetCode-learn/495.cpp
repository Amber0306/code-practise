#include<iostream>
#include<vector>

using namespace std;



int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int alltime=0;
        int i;
        for(i=0;i<timeSeries.size()-1;i++){
            if(timeSeries[i]+duration<=timeSeries[i+1]){
                alltime+=duration;
            }else{
                alltime=alltime+timeSeries[i+1]-timeSeries[i];
            }
        }
        return alltime;
}

int main(){
    cout<<"hello world"<<endl;
    vector<int> timeSeries;
    timeSeries.push_back(1);
    timeSeries.push_back(2);
    timeSeries.push_back(10000000);
    int result = findPoisonedDuration(timeSeries,2);
    cout<<result<<endl;
    return 0;
}
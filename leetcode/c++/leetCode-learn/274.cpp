#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int> &citations)
{
    //降序排序
    sort(citations.rbegin(), citations.rend());
    //
    int cite = 0;
    int n=citations.size();
    for (int i = 0; i < n; i++)
    {
        // int numTemp=0;
        // int targetCite=citations[i];
        // if(targetCite>n){
        //     continue;
        // }
        // for(int j=0;j<n;j++){
        //     if(citations[j]>=targetCite){
        //         numTemp++;
        //     }else{
        //         break;
        //     }
        // }
        // if(numTemp>=targetCite){
        //     cite = targetCite;
        //     return targetCite;
        // }
        if(citations[i]<i){
            cite=i;
            break;
        }
    }
    return cite;
}

int main()
{
    vector<int> citations = {3,0,6,1,3};
    int result = hIndex(citations);
    cout << result << endl;
    system("pause");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//It can be applied on a array containing element 0 to 1e9
//Time complexity is O(n+r) where n is the number of elements and r is the range of count array
vector<int> countSort(vector<int> &v){
    //Find the max element to know the lenght of count array
    int maxElement=*max_element(v.begin(),v.end());

    vector<int> count(maxElement+1);
    //Store the count of elements in the array like hashmap
    for(int i=0;i<v.size();++i){
        count[v[i]]++;
    }
   //Calculate prefix sum of count array as 1,1,2,4=1,2,4,8
    for(int i=1;i<count.size();++i){
        count[i]+=count[i-1];
    }
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;--i){
        // int permissibleIndex=--count[v[i]];
        // int temp=v[i];
        // ans[permissibleIndex]=temp;
        ans[--count[v[i]]]=v[i];
    }
    return ans;
}

int main(){
vector<int> v={1,3,0,2,2,4,6};
cout<<"Before ::: ";
for(int i=0;i<v.size();++i){
    cout<<v[i]<<" ";
}cout<<endl;

auto ans=countSort(v);


cout<<"After ::: ";

for(int i=0;i<ans.size();++i){
    cout<<ans[i]<<" ";
}

}
#include<bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int> &v){
    int maxElement=*max_element(v.begin(),v.end());

    vector<int> count(maxElement+1);

    for(int i=0;i<v.size();++i){
        count[v[i]]++;
    }
   
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
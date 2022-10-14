#include<bits/stdc++.h>
using namespace std;

//Complexity=O(numberOfDigits*(n+range));
void countSort(vector<int> &v,int base){
    int n=v.size();
    vector<int> count(10,0);

    for(int i=0;i<n;++i){
        count[(v[i]/base)%10]++;
    }
    for(int i=1;i<10;++i){
        count[i]+=count[i-1];
    }
    vector<int> output(n);
    for(int i=n-1;i>=0;--i){
        output[--count[(v[i]/base)%10]]=v[i];
    }
    v=output;
}
void redixSort(vector<int> &v){
    int maxElement=*max_element(v.begin(),v.end());

    for(int base=1;maxElement/base>0;base*=10){
        countSort(v,base);
    }
}
void printVector(vector<int> &v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v={97,57,208,699,125,734};
    int n=v.size();
    cout<<"Before Sorting : ";
    printVector(v);

    redixSort(v);
    cout<<"After Sorting : ";
    printVector(v);
}
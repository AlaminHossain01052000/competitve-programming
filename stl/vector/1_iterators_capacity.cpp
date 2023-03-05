#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    
    cout<<"Enter vector size : ";
    int size;
    cin>>size;
    v.assign(size,0);
    int j=0;
    for(int i=0;i<size;++i){
        v[i]=j+=2;
    }
    cout<<"The vector in reversed order : ";
    for(auto it=v.rbegin();it!=v.rend();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.reserve(100);
    v.shrink_to_fit();//make capacity=size
    cout<<v.size()<<" "<<v.capacity()<<endl;

    
    cout<<v.front()<<" "<<v.back()<<endl;
    cout<<*v.begin()<<endl;
}
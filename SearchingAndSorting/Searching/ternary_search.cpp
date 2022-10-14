#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int low,int high,int key,vector<int> &v){
    if(low<=high){
        int mid1=low+((high-low)/3);
        int mid2=high-((high-low)/3);
        if(key==v[mid1]){
            return mid1;
        }
        else if(key==v[mid2]){
            return mid2;
        }
        else if(key<v[mid1]){
            return ternarySearch(low,mid1-1,key,v);
        }
        else if(key>v[mid2]){
            return ternarySearch(mid2+1,high,key,v);
        }
        else return ternarySearch(mid1+1,mid2-1,key,v);
    }
    return -1;

}
int main(){
    vector<int> v={-110,-23,-5,-2,-2,1,0,11,23,45,66,99,101,1234,4561};
    int key=45;
    cout<<key<<" is found in index "<<ternarySearch(0,v.size()-1,key,v);

}
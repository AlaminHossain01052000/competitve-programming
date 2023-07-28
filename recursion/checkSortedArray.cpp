#include<bits/stdc++.h>
using namespace std;

bool isSorted(int v[],int n){
    if(n<=1){
        return true;
    }
    cout<<v[0]<<" "<<v[1]<<endl;
    if(v[0]>v[1]){
        return false;
    }
    else {
        return isSorted(v+1,n-1);
    }

}
int main(){
    int v[]={2,4,6,9,11,13};
    int n=6;
    if(isSorted(v,n)){
        cout<<"Sorted"<<endl;
    }
    else cout<<"Unsorted";
}
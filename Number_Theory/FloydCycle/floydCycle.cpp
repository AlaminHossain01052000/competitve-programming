#include<bits/stdc++.h>
using namespace std;
bool floydCycleDetection(int *a,int n){
    int tortoise=0;
    int rabbit=0;
    for(int i=0;i<n;++i){
        tortoise++;
        rabbit+=2;
        if(tortoise<n&&rabbit<n){
            if(a[tortoise]==a[rabbit])
                return true;
        }
    }
    return false;
}
int repeatedPointDetection(int *a,int n){
    int tortoise=0;
    int rabbit=0;

    for(int i=0;i<n;++i){
        for(int i=0;i<n;++i){
        tortoise++;
        rabbit+=2;
        if(tortoise<n&&rabbit<n){
            if(a[tortoise]==a[rabbit])
                return a[tortoise-1];
        }
    }
    }

}
int main(){
    int a[12];
    int value=4;
    for(int i=0;i<12;++i){
        if(value==8){
            a[i]=4;
            value=5;
        }
        else{
            a[i]=value;
            value++;
        }
        // a[i]=value;
        // value++;
        
    }
    for(int i=0;i<12;++i){
       cout<<a[i]<<" ";
    }
    bool ans=floydCycleDetection(a,12);
    cout<<endl;
    cout<<ans<<endl;
    if(ans){
        int repeatedNode=repeatedPointDetection(a,12);
        cout<<repeatedNode<<endl;
        int lengthOfUnrepeatedData=0;
        for(int i=0;i<12;++i){
            if(a[i]==repeatedNode){
                lengthOfUnrepeatedData++;
                break;
            }
            lengthOfUnrepeatedData++;
        }
        cout<<lengthOfUnrepeatedData<<endl;
    }
    return 0;
}
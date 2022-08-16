#include<bits/stdc++.h>
using namespace std;

int eulerTottient(int n){
   int result=n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            result=(result-(result/i));
    
        }
       
    } 
    if(n>1){
        result=(result-(result/n));
    }
    return result;
    
}


int main(){
    while(1){
        int n;
        cin>>n;
        cout<<eulerTottient(n)<<endl;

        
    }

}
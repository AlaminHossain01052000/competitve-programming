//Print the value of catalan number till n
#include<bits/stdc++.h>
using namespace std;

int catalan(int n){
    if(n<=1) return 1;
    int result=0;
    for(int i=0;i<=n-1;i++){
        result+=catalan(i)*catalan(n-i-1);
    }
    return result;
}
int main(){
    for(int i=1;i<=10;++i){
        cout<<i<<" "<<catalan(i)<<endl;
    }

}
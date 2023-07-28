#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;//As we want to find accuracy till 0.000001
double multiply(double x,double y){
    double res=1.0;
    for(int i=1;i<=y;++i){
        res*=x;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        double x;
        int n;
        cin>>x>>n;
        double low=1;
        double high=x;
        while(high-low>eps){
            double mid=(low+high)/2;
            if(multiply(mid,n)<x){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        cout<<setprecision(6)<<low<<" "<<high<<" "<<pow(x,1.0/n)<<endl;
        
    }
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N][3];
int n;
int tasksPoint[N][3];
int vacation(int day,int choosedDay){
    if(day==n) return 0;
    if(choosedDay!=-1)
        if(dp[day][choosedDay]!=-1)return dp[day][choosedDay];
    int x=INT_MIN;
    for(int i=0;i<3;++i){
        if(choosedDay!=i){
             x=max(x,vacation(day+1,i)+tasksPoint[day][i]);
        }
    }
    return dp[day][choosedDay]=x;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            cin>>tasksPoint[i][j];
        }
    }
    cout<<vacation(0,-1)<<endl;

    return 0;
}


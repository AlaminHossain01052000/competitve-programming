// https://codeforces.com/contest/1881/problem/C -90 degree rotation
//https://codeforces.com/problemset/problem/1703/E -0,90,180,270 degree rotation
//this template is suitable for this 2 types of rotation

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define endl '\n'
//generating the related row no and column no 
vector<vector<pair<int, int>> > built(int n) {
    // vector<vector<pair<int, int>> arr(n + 1, vector<pair<int, int>>(n + 1));
    vector<vector<pair<int, int>>> arr(n+1,vector<pair<int, int>>(n+1));
    for(int i = 1; i <= n; ++i) {
        int k=n;
        for(int j = 1; j <= n; ++j) {
            arr[i][j] = {k--, i};
        }
    }
    return arr;
}
void solve(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    auto arr2=built(n);//arr2 is the symmetric or related row and column no
    int ans=0;
    vector<vector<bool>> isCalculated(n+1,vector<bool>(n+1,false));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(isCalculated[i][j])continue;
            isCalculated[i][j]=true;
            int r1=i;
            int c1=j;
            int r2=arr2[i][j].first;
            int c2=arr2[i][j].second;
            int r3=arr2[r2][c2].first;
            int c3=arr2[r2][c2].second;
            int r4=arr2[r3][c3].first;
            int c4=arr2[r3][c3].second;
            //the 4 characters of below are related or they will be exchanged when mirror or grid will rotate
            char ch1=arr[r1-1][c1-1];
            char ch2=arr[r2-1][c2-1];
            char ch3=arr[r3-1][c3-1];
            char ch4=arr[r4-1][c4-1];
            char maxChar='a';
            for(char ch='a';ch<='z';++ch){
                if(ch==ch1||ch==ch2||ch==ch3||ch==ch4)
                    maxChar=max(maxChar,ch);
            }
            ans+=abs(maxChar-ch1);
            ans+=abs(maxChar-ch2);
            ans+=abs(maxChar-ch3);
            ans+=abs(maxChar-ch4);
            isCalculated[r3][c3]=true;
            isCalculated[r2][c2]=true;
            isCalculated[r4][c4]=true;
        }
        
    }
    cout<<ans<<endl;

}
int main(){
    fast
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
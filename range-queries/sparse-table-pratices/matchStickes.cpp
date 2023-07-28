// https://www.codechef.com/problems/MSTICK?tab=submissions
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
const int N=1e5+100;
const int K=log2(1e5+100)+1;
const int INF=1e9+100;
vector<vector<int>>stMin(K,vector<int>(N,INF));
vector<vector<int>>stMax(K,vector<int>(N,INF*-1));
void stBuild(vector<int> &v){
    int n=v.size();
    
    for(int j=0;j<n;++j){
        stMax[0][j]=v[j];
        stMin[0][j]=v[j];
    }

    for(int i=1;i<=K;++i){
        for(int j=0;j+(1<<i)<=n;++j){
            stMin[i][j]=min(stMin[i-1][j],stMin[i-1][j+(1<<(i-1))]);
            stMax[i][j]=max(stMax[i-1][j],stMax[i-1][j+(1<<(i-1))]);
        }
    }
}
int32_t main() {
	// your code goes here
    fast
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;++i)cin>>v[i];
    stBuild(v);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int minInRange=v[l];
        int maxInRange=v[r];
        int i=log2(r-l+1);
        if(r-l+1>1){
            
             minInRange=min(stMin[i][l],stMin[i][r-(1<<i)+1]);
             maxInRange=max(stMax[i][l],stMax[i][r-(1<<i)+1]);
        }
        

        i=log2(l);
        int maxInLeft=0;
        if(l>0){
            maxInLeft=max(stMax[i][0],stMax[i][(l-1)-(1<<i)+1]);
        }
        
        i=log2((n-1)-(r+1)+1);
        int maxInRight=0;
        if(r+1<n){
            maxInRight=max(stMax[i][r+1],stMax[i][(n-1)-(1<<i)+1]);
        }
        
        double x=(maxInRange+minInRange)/2.0;
        double y=minInRange+0.0+maxInLeft;
        double z=minInRange+0.0+maxInRight;
        double ans=max(x,y);
        // cout<<x<<" "<<y<<" "<<z<<endl;
        cout<<max(ans,z)<<endl;
    }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> prefixSum(n+1,vector<int>(m+1));
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            prefixSum[i][j]=0;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            prefixSum[i][j]=prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1]+v[i][j];
        }
    }
    cout<<"Given Martix : \n";
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Prefix Matrix : \n";
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cout<<prefixSum[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Enter number of query : ";
    int q;
    cin>>q;
    for(int i=1;i<=q;++i){
        cout<<"Enter 4 index to form a rectangle. Suppose (1,1),(2,2) will form a rectangle using the elements (1,1),(1,2),(2,1),(2,2)\n";
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int sum=prefixSum[c][d]-prefixSum[a-1][d]-prefixSum[c][b-1]+prefixSum[a-1][b-1];

        //Nothing but adding some beauty in the code
        for(int i=a;i<=c;++i){
            for(int j=b;j<=d;++j){
                if(i==c&&j==d){
                    cout<<v[i][j]<<" = ";
                }
                else cout<<v[i][j]<<" + ";
                
            }
        }
        cout<<sum<<endl;
    }
}
// Sample Input:
// 5 4
// 1 3 2 5 
// 9 1 7 2
// 6 4 3 5
// 11 5 2 6
// 0 9 8 6
// 1
// 2 2 4 4

// Sample Output:
// 5 4
// 1 3 2 5        
// 9 1 7 2        
// 6 4 3 5        
// 11 5 2 6       
// 0 9 8 6        
// Given Martix : 
// 1 3 2 5        
// 9 1 7 2        
// 6 4 3 5        
// 11 5 2 6       
// 0 9 8 6

// Prefix Matrix :
// 1 4 6 11
// 10 14 23 30 
// 16 24 36 48
// 27 40 54 72
// 27 49 71 95 

// Enter number of query : 1
// Enter 4 index to form a rectangle. Suppose (1,1),(2,2) will form a rectangle using the elements (1,1),(1,2),(2,1),(2,2)
// 2 2 4 4
// 1 + 7 + 2 + 4 + 3 + 5 + 5 + 2 + 6 = 35
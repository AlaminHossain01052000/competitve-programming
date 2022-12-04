#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v[N][N];
int rows,columns;
bool isSafe(int r,int c,int v[]){
    if(r<0||c<0)return false;

    if(r==rows){
        return false;
    }
    if(c==columns){
        return false;
    }
    if(r-1>=0){
        if(v[r-1][c]==0){
            return false;
        }
    }
    if(r+1<rows){
        if(v[r+1][c]==0){
            return false;
        }
    }
    if(c+1<columns){
        if(v[r][c+1]==0){
            return false;
        }
    }
    if(c-1>=0){
        if(v[r][c-1]==0){
            return false;
        }
    }
   
    return true;
}
int solve(int r,int c,int v[]){
    if(c==columns-1){
        return 1;
    }
    if(r==rows){
        return 0;
    }
    int ans=INT_MAX;
    if(isSafe(r,c+1)){
        ans=solve(r,c+1)+v[r][c];
    }
    if(isSafe(r+1,c)){
        ans=min(ans,solve(r+1,c)+1)+v[r][c];
    }
   
    return ans;
}
int main(){
    rows=12;
    columns=10;
    int mat[rows][columns] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    int a=INT_MAX;
    for(int i=0;i<rows;++i){
        a=min(a,solve(i,0,mat));
    }
}
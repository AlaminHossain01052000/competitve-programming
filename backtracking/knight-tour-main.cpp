#include<bits/stdc++.h>
using namespace std;
vector<int> availableRowPaths;
vector<int> availableColumnPaths;
bool isSafe(vector<vector<int>> &v,int r,int c,int n){
     
        if(r<n&&r>=0&&c>=0&&c<n&&v[r][c]==-1){
            return true;
        }
        return false;
}

bool knightTour(vector<vector<int>> &v,int r,int c,int n,int cellMark){

    if(cellMark==n*n-1){
        for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
        return true;
    }
    else{
    for(int i=0;i<n;++i){
        if(isSafe(v,r+availableRowPaths[i],c+availableColumnPaths[i],n)){
            ++cellMark;
            v[r+availableRowPaths[i]][c+availableColumnPaths[i]]=cellMark;

            if(knightTour(v,r+availableRowPaths[i],c+availableColumnPaths[i],n,cellMark)){
                return true;
            }
            else{
                --cellMark;
                v[r+availableRowPaths[i]][c+availableColumnPaths[i]]=-1;
            }
            
        }
    }
    }
    if(r==0&&c==0){
        cout<<"Solution does not exist\n";
    }
   return false;
}
int main(){
    int n=6;
    vector<vector<int>> v={
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
       
               
    };
    v[0][0]=0;
    availableRowPaths={-2,-2,-1,-1,1,1,2,2};
    availableColumnPaths={-1,1,-2,2,-2,2,-1,1};
    knightTour(v,0,0,n,0);
  
}
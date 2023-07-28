#include<bits/stdc++.h>
using namespace std;
int numberOfVisitedCells=0;
// bool isSafe(vector<vector<int>>&v,int i,int j,int n){
//     int x=i-2;
//     int y=j-1;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i-2;
//     y=j+1;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i-1;
//     y=j-2;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i-1;
//     y=j+2;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i+1;
//     y=j-2;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i+1;
//     y=j+2;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i+2;
//     y=j-1;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     x=i+2;
//     y=j+1;
//     if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==0){
//         return true;
//     }
//     return false;
// }
void knightTour(vector<vector<int>>&v,int numberOfVisitedCells,int currentIndex,int j,int n){
    int i=currentIndex;
    if(numberOfVisitedCells==n*n){
        return;
    }
    v[currentIndex][j]=numberOfVisitedCells;

    int x=i-2;
    int y=j-1;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i-2;
    y=j+1;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i-1;
    y=j-2;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i-1;
    y=j+2;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i+1;
    y=j-2;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i+1;
    y=j+2;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i+2;
    y=j-1;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
    x=i+2;
    y=j+1;
    if(x>=0&&x<n&&y>=0&&y<n&&v[x][y]==-1){
        ++numberOfVisitedCells;
        knightTour(v,numberOfVisitedCells,x,y,n);
    }
   
}

int main(){
    int n=8;
    vector<vector<int>> v={
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1}
        
        
    };
    knightTour(v,0,0,0,n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
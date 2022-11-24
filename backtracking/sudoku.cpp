#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &v,int r,int c,int num){
    for(int i=0;i<9;++i){
        if(v[i][c]==num){
            return false;
        }
        if(v[r][i]==num){
            return false;
        }
    }
    int startRow=r-(r%3);
    int startColumn=c-(c%3);

    for(int i=startRow;i<startRow+3;++i){
        for(int j=startColumn;j<startColumn+3;++j){
            if(v[i][j]==num)return false;
        }
    }
   
    return true;
}

bool sudoku(vector<vector<int>> &v,int r,int c){
    if(r==8&&c==9){
        return true;
    }
    if(c==9){
        r++;
        c=0;
    }
    if(v[r][c]>0){
        return sudoku(v,r,c+1);
    }
    for(int i=1;i<=9;++i){
        if(isSafe(v,r,c,i)){
            v[r][c]=i;
            if(sudoku(v,r,c+1)){
                return true;
            }
            v[r][c]=0;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> v = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(sudoku(v,0,0)){
        for(auto row:v){
            for(auto ele:row){
                cout<<ele<<" ";
            }cout<<endl;
        }
    }
    else cout<<"No solution is exist\n";
}
// Question Link:https://www.spoj.com/problems/NAKANJ/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9+10;
int visited[8][8]; //Here the chess is 8 X 8
int level[8][8];
//All possible movements of a knight in a chessboard
vector<pair<int,int>> movements={
    {1,2},
    {-1,2},
    {-2,1},
    {-2,-1},
    {2,1},
    {2,-1},
    {-1,-2},
    {1,-2}
};
//ensure that the knight must be in the board
bool isValid(int x,int y){
    return x>=0&&y>=0&&x<8&&y<8;
}
int getXCordinate(string s){
    //let,s=a1 the here x=1 and y=1 for 1 based array. If s=c3 then x=3 and y=3
    return s[0]-'a'; //Though above example for 1 based array but it will return 0 for a, 1 for b...7 for h

}
int getYCordinate(string s){
    return s[1]-'1';//it will return 0 for a1, 1 for b2 ...7 for h8
}
int bfs(string source,string destination){

        int sourceX=getXCordinate(source);
        int sourceY=getYCordinate(source);
        int destiX=getXCordinate(destination);
        int destiY=getYCordinate(destination);

        queue<pair<int,int>> q;//Generally in bfs you use queue to store an integer but in matrix form of input we need to store the x-coordinate and y-coordinate as pair

        q.push({sourceX,sourceY});
        visited[sourceX][sourceY]=1;
        level[sourceX][sourceY]=0;
        while(!q.empty()){
            pair<int,int> current_cell=q.front();
            int x=current_cell.first;
            int y=current_cell.second;
            q.pop();
            for(auto movement:movements){
                int movementToX=x+movement.first;
                int movementToY=y+movement.second;
                if(!isValid(movementToX,movementToY))continue;
                if(visited[movementToX][movementToY]==1)continue;
                q.push({movementToX,movementToY});
                visited[movementToX][movementToY]=1;
                level[movementToX][movementToY]=level[x][y]+1;//child level=parent level+1
                //If the level of destination is calculated then
                if(level[destiX][destiY]!=INF){
                    break;
                }
            }
        }
        return level[destiX][destiY];

}
//As there are several testcases so we have to reset all the values before every calculation
void reset(){
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            visited[i][j]=0;
            level[i][j]=INF;//set every level as infinity
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        reset();
        cout<<bfs(s1,s2)<<endl;
    }
}
//Sample input
// 3
// a1 h8
// a1 c2
// h8 c3

//Sample output
// 6
// 1
// 4
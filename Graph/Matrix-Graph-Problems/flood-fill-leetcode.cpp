// https://leetcode.com/problems/flood-fill/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
void dfs(int i,int j,int initialColor,int newColor,vector<vector<int>>& image){
    int numberOfRows=image.size();
    int numberOfColumns=image[0].size();
    if(i<0||j<0)return;
    if(i>=numberOfRows||j>=numberOfColumns)return;
    if(image[i][j]!=initialColor)return;
    image[i][j]=newColor;

    dfs(i-1,j,initialColor,newColor,image);
    dfs(i+1,j,initialColor,newColor,image);
    dfs(i,j-1,initialColor,newColor,image);
    dfs(i,j+1,initialColor,newColor,image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    if(image[sr][sc]!=color)    //If initialColor!=newColor
        dfs(sr,sc,image[sr][sc],color,image);   //image[sr][sc]=initialColor
    return image;
}
int main(){
    vector<vector<int>> graph;
    graph={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    graph=floodFill(graph,1,1,2);
    for(auto vect:graph){
        for(auto ele:vect){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}
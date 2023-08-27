// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1
//{ Driver Code Starts
#include<bits/stdc++.h>
// #include<algorithm>
// #include<queue>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	struct info{
	    int x,y;  
	};
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        // vector<pair<int,int>> distance(n+1,INF);
        int distance[n][n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                distance[i][j]=INT_MAX;
            }
        }
        // return 1;
    // priority_queue<pair<int,int>> pq;//by default it is max heap but we need min heap
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;//min heap
    
    pq.push({grid[0][0],{0,0}});
    distance[0][0]=grid[0][0];
    while(!pq.empty()){
        auto parentNode=pq.top().second;
        int parentDistance=pq.top().first;
        pq.pop();
        if(distance[parentNode.first][parentNode.second]<parentDistance)continue; //elementing the unnecessary node
        int currentX=parentNode.first;
        int currentY=parentNode.second;
        int newX=currentX+0;
        int newY=currentY-1;
        if(newX>=0&&newY>=0&&newX<n&&newY<n){
            int childWeight=grid[newX][newY];
            if(childWeight+parentDistance<distance[newX][newY]){
                distance[newX][newY]=childWeight+parentDistance;
                
                pq.push({distance[newX][newY],{newX,newY}});
            }
        }
         newX=currentX+0;
         newY=currentY+1;
        if(newX>=0&&newY>=0&&newX<n&&newY<n){
            int childWeight=grid[newX][newY];
            if(childWeight+parentDistance<distance[newX][newY]){
                distance[newX][newY]=childWeight+parentDistance;
                
                pq.push({distance[newX][newY],{newX,newY}});
            }
        }
         newX=currentX-1;
         newY=currentY+0;
        if(newX>=0&&newY>=0&&newX<n&&newY<n){
            int childWeight=grid[newX][newY];
            if(childWeight+parentDistance<distance[newX][newY]){
                distance[newX][newY]=childWeight+parentDistance;
                
                pq.push({distance[newX][newY],{newX,newY}});
            }
        }
         newX=currentX+1;
         newY=currentY+0;
        if(newX>=0&&newY>=0&&newX<n&&newY<n){
            int childWeight=grid[newX][newY];
            if(childWeight+parentDistance<distance[newX][newY]){
                distance[newX][newY]=childWeight+parentDistance;
                
                pq.push({distance[newX][newY],{newX,newY}});
            }
        }
        
        
    }
    return distance[n-1][n-1];
    }
    
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
// 1
// 4
// 9 4 9 9
// 6 7 6 4
// 8 3 3 7
// 7 4 9 10
//Ans:43
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int m = edges.size();
	    int inf = 10000000;
	    vector<int> dist(n,inf);
	    dist[0] = 0;
	    
	    for(int i = 0; i < n-1; i++){       //Relaxing all the edges N-1 times
	        for(int j = 0; j < m; j++){
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int wt = edges[j][2];
	            if(dist[u] + wt < dist[v]){
	                dist[v] = dist[u] + wt;
	            }
	        }
	    }
	    
	    //if relaxing nth time gives less distance then there is a negative cycle
	    for(int i = 0; i < m; i++){
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int wt = edges[i][2];
	        if(dist[u] + wt < dist[v]){
	            return 1;
	        }
	    }
	    
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
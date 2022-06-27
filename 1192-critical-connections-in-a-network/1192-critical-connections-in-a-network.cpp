class Solution {
public:    
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<vector<int>> &ans)
    {
        //when we visite node first time, tin and low of the node are equal to the time
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for(auto it : adj[node]){
            if(it == parent){ 
                continue;             //to avoid backtracking
            }
            
            //if node is not visited, call the dfs function
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj,ans);
                //when we return, low of the node is equal to the minimum of low of its child and low of itself
                low[node] = min(low[node], low[it]);
                
   //when we get low of child is greater than tin of the node
  //it means there is only path to cover child that's why {node, it} will be our critical connections or bridge 
                if(low[it] > tin[node]){
                    ans.push_back({node,it});
                }
            }
            
             //if node is already visited and tin of the child is less than the low of itself
            //we assign tin of the child to the low of the node
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //tin - time of insertion at the node
        //low - lowest time of insertion at the node
        //vis - mark visited node 
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        int timer = 0;
        
        dfs(0,-1,vis,tin,low,timer,adj,ans);
        
        return ans;
    }
};
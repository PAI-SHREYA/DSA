#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	
	void dfs(int start,vector<int> adj[],vector<bool> &vis,stack<int> &s)
	{
	    vis[start]=true;
	    for(auto it:adj[start])
	    {
	        if(!vis[it])
	        dfs(it,adj,vis,s);
	    }
	    s.push(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	  
	    vector<bool> vis(V,false);
	    vector<int> ans;
	    stack<int> s;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,s);
	        }
	    }
	    
	    
	    while(!s.empty())
	    {
	        ans.push_back(s.top()); s.pop();
	    }
	    return ans;
	}
};
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}

/*
  180 Daraga Training
  Session No : 12
  Session : Graph Traverse
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = 2e3 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.0000001, PI = 2*acos(0.0);

vector<int> adjList[N];					//unweighted adjacency list
stack<int> st;
queue<int> q;
bool vis[N];

int n, m, u, v, c;

void recursive_dfs (int s){
    vis[s]=1;
    cout<<s<<" ";
    for(int u : adjList[s]){ /// 1: 3 2  //// n * n >> O(n^2)
        if(!vis[u])
            recursive_dfs(u);
    }
}

void dfs(int s){
    vis[s] = 1;
    st.push(s);
    while(!st.empty()){
        int cur = st.top();
        cout<<cur<<" "; /// dfs 1 3 7 6 2 5 4
        st.pop();
        for(int u:adjList[cur]){
            if(!vis[u]){
                st.push(u);
                vis[u]=1;
            }
        }
    }
}

void bfs(int s){
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        cout<<cur<<" "; /// 1 2 3 4 5 6 7
        q.pop();
        for(int u:adjList[cur]){
            if(!vis[u]){
                q.push(u);
                vis[u]=1;
            }
        }
    }
}


int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);

    /// 5 6
    /// 1 2
    /// 2 3
    /// 1 4
    /// ...
 	//cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){			//number of edges
		cin >> u >> v;	// from, to
		adjList[u].push_back(v);
		adjList[v].push_back(u);			//for undirected graphs
	}
    /// 1 :3  2
    /// 2 :1
    /// 3 :1
    /// 4

   /*
    for(int i=0;i<n;i++)
    if(!vis[u]){
        cnt++;
        dfs(u);
    }
    */
	recursive_dfs(1);
	cout<<endl;
	memset(vis,0,sizeof vis);
	dfs(1);
	cout<<endl;
	memset(vis,0,sizeof vis);
	bfs(1);


  	return 0;
}


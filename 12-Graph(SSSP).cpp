/*
  180 Daraga Training
  Session No : 12
  Session : Graph-ClassicalProblem-SSSP
  			Single Source Shortest Path
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5, OO = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 0.000000001;

int n, m, a, b, x;
vector<int> adj[N];
int dis[N];

void BFS(int src){
	queue<int> q;
	q.push(src);
	dis[src] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int ch : adj[p])if(dis[ch]==OO){
			q.push(ch);
			dis[ch] = dis[p] + 1;
		}
	}
}

int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> x;
	memset(dis, -1, sizeof dis);
	BFS(x);
	for(int i = 1 ; i <= n ; ++i)
		printf("The Shortest Path between %d and %d is %d\n", x, i, dis[i]);
	return 0;
}


/// Topological ordering
/*
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.000000001;

int n, m, u, v;
vector<int> adj[N];
bool vis[N];
stack<int> topo;

void DFS(int p){			//iterative DFS
	stack<int> st;
	st.push(p);
	//topo.push(p);
	vis[p] = 1;
	while(!st.empty()){
		int p = st.top();
		st.pop();
		for(int ch : adj[p]){
			if(!vis[ch]){
                st.push(ch);
                //topo.push(p);
                vis[ch] = 1;
            }
		}
	}
}


void DFS(int p){
    /// DFS (1, )
    /// 4 2 5 6 3 1
    /// 1 >> 2,3
    /// 2 >> 4
    /// 3 >> 5,6
    /// 5 6 3 4 2 1         //topological ordering
    /// 4 2 5 6 3 1
	vis[p] = 1;
	for(int ch : adj[p])			//Finish all the dependencies
		if(!vis[ch])	DFS(ch);	//..,

	printf("%d ", p);					//then print me
}


int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i){
		cin >> u >> v;
		adj[v].push_back(u);					//Reverse edges
	}
	for(int i = 1 ; i <= n ; ++i){	//-try to-Traverse starting from each non-visited node
		if(!vis[i])	DFS(i);
	}
	while(!topo.empty()){
        cout<<topo.top();
        topo.pop();
	}
	return 0;
}

/*
  180 Daraga Training
  Session No : 11
  Session : Graph Representation
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include 
<bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = 2e3 + 5, OO = 0x3f3f3f3f;
const double EPS = 0.0000001, PI = 2*acos(0.0);

vector<pair<int, int> > edgelist;			//unweighted edge list
vector<pair<int, pair<int, int> > wEdgeList;		//weighted edge list

bool adjMat[N][N];					//unweighted adjacency matrix
int wAdjMat[N][N];					//weighted adjacency matrix

vector<int> adjList[N];					//unweighted adjacency list
vector<pair<int, int> > wAdjList[N];			//weighted adjacency list

int n, m, u, v, c;

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

        adjMat[u][v] = c;
        //adjMat[v][u] = c;			//for undirected graphs


		adjList[u].push_back(v);
		//adjList[v].push_back(u);			//for undirected graphs

		///	in a weighted graph
		/*
		cin >> u >> v >> c; /// 1 7 10
		wAdjList[u].push_back({c, v});
		wAdjList[v].push_back({c, u});
        */
        ///wAdjList[1] = v = [{5,2} , {3,4} , {2,5}] >> v[0]
		/// wAdjList[1][2].second
            /// v= [1, 3, 5, 4]
            /*
            for(int i=1;i<=n;i++){
                for(pair<int, int> e : wAdjList[2]){
                    cout<<e.first; /// 1354
                    cout<<e.second;
                }
            }
            */
			///using adjacency matrix
        /*
        cin >> u >> v >> c;
		wAdjMat[u][v] = c;
		wAdjMat[v][u] = c;
		*/

	}
  	return 0;
}
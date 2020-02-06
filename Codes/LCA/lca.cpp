//LCA of tree (Least Commn Ancestor)
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 22;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;
int n;					  //no of nodes
vector <int> g[100005];   //graph -> 1 based indexing
int sparse[100007][N+3];  // 2^i distance parent
int par[100007];          //parent of each node
int level[100007];        //level of each node

void dfs (int u, int pr, int lvl) {
	par[u] = pr;
	level[u] = lvl;
	for (int v : g[u]) {
		if (v != pr)
			dfs (v, u, lvl+1);
	}
}

//Store the parent of node at (2^i) distance
void sparse_build () {
	sparse[0][0] = 0;
	for (int i=1; i<=n; i++) {
		sparse[i][0] = par[i];
	}
	//par[2^i] = par[2^(i-1)] + par[2^(i-1)]
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=n; j++) {
			int v = sparse[j][i-1];
			sparse[j][i] = sparse[v][(i-1)];
		}
	}
}

int LCA (int u, int v) {
	if (level[u] < level[v])
		swap (u, v);
	int dif = level[u] - level[v];
	//move to same level in powers of 2
	for (int i=N; i>=0; i--) {
		if ((1ll<<i) & (dif))
			u = sparse[u][i];
	}
	//move to farthest not equal nodes
	if (u == v)
		return u;
	for (int i=N; i>=0; i--) {
		if (sparse[u][i] && sparse[v][i] && (sparse[u][i] != sparse[v][i])) {
			u = sparse[u][i];
			v = sparse[v][i];
		}
	}
	return sparse[u][0];
}

void testCase() {
    cin >> n;
    for (int i=1; i<n; i++) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back (v);
    	g[v].push_back (u);
    }
    //Find Parent and level of each node
    dfs (1, 0, 1);
    //BUILD SPARSE TABLE
    sparse_build ();
    //LCA (u, v)
    //bring u amd v to same level
    int u, v;
    cin >> u >> v;
    cout << LCA (u, v) << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
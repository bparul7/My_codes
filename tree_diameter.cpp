//diameter of any connected component is the maximum of all shortest paths in the graph
// TREE DIAMETER
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > g(200000);
int node = -1, mx = 0;
int diameter = 0;
int mx_node[200000];
//dfs for 2DFS method
void dfs(int u, int p, int dis) {
	if (dis > mx) {
		mx = dis;
		node = u;
	}
	for (int v=0; v<g[u].size(); v++) {
		if (g[u][v] != p) {
			dfs(g[u][v], u, dis+1);
		}
	}
}
//calculates max height of each subtree
int dfs_sz(int u, int p) {
	mx_node[u] = -1;
	for (int v=0; v<g[u].size(); v++) {
		if (g[u][v] != p) {
			mx_node[u] = max(mx_node[u], dfs_sz(g[u][v], u));
		}
	}
	mx_node[u]++;
	return mx_node[u];
}
//calculates dia in tree
void dia(int u, int p) {
	int d = 2;
	int mx1 , mx2;
	mx1 = mx2 = 0;
	for (int v=0; v<g[u].size(); v++) {
		if (g[u][v] != p) {
			if (mx_node[g[u][v]] >= mx1) {
				mx2 = mx1;
				mx1 = mx_node[g[u][v]];
			}
			else if (mx_node[g[u][v]] > mx2) {
				mx2 = mx_node[g[u][v]];
			}
		}
	}
	d += mx1 + mx2;
	if (d > diameter) {
		diameter = d;
	}
	for (int v=0; v<g[u].size(); v++) {
		if (g[u][v] != p) {
			dia(g[u][v], u);
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// 2 DFS method
	// diameter will lie along the subtree of largest size (by contradiction)
	// r = farthest (s), t = farthest (r), diameter = (r-t)
	dfs(1, 0, 0);
	mx = 0;
	dfs(node, 0, 0);
	cout << mx << endl;
	// for each node checking whether diameter pass through that node
	// sum up two max for each node and update diameter and recur on all subtrees
	dfs_sz(1, 0);
	dia(1, 0);
	cout << diameter << endl;

}

//centroid in a connected component : It is the node which when removed leaves the minimum size of subtree
//centre of a connected component : It is the node through which the farthest node is at minimum distance
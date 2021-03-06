/* find_set(v) : This operation will return the id of the representative of the group in which v is present
   union_set(u, v) : This operation will join the groups if u and v are present in different groups
   make_set(v) : This will make a new group containing single node v */
#include<bits/stdc++.h>
using namespace std;

int par[100000]; //index->node no and value->parent of that node
int sz[1000000]; //index->node no and value->size of group in which node is present
int connected;

void make_set (int v) {
	par[v] = v;
	sz[v] = 1;
}

void init( int n ) {
	for (int i=1; i<=n; i++) {
		make_set(i);
	}
	connected = n;
}

int find_set (int v) {
	if (v == par[v])
		return v;
	return( par[v] = find_set(par[v]) );
}

void union_set (int u, int v) {
	u = find_set(u);
	v = find_set(v);
	if (u != v) {
		connected--;
		if (sz[u] <= sz[v]) {
			par[v] = u;
			sz[u] += sz[v];
			sz[v] = 0;
		}
		else {
			par[u] = v;
			sz[v] += sz[u];
			sz[u] = 0;
		}
	}
}

int main() {
	make_set(1);
	cout << find_set(1) << endl;
	return 0;
}

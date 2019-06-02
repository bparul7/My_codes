/* 2D dsu is used when dsu is applied to n id's */
#include<bits/stdc++.h>
using namespace std;
const int N = 10007;

int par[N][N];	//par of each node for each id
int sz[N][N];	//size of dsu for each id
int cn[N];     //no of connected component for particular dsu

void init (int n) {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			par[i][j] = j;
			sz[i][j] = 1;
		}
		cn[i] = n;
	}
}

int find_set (int id, int v) {
	if (par[id][v] == v)
		return v;
	return (par[id][v] = find_set(id, par[id][v]));
}

void swap (int *u, int *v) {
	int temp = (*u);
	(*u) = (*v);
	(*v) = temp;
}

void union_set(int id, int u, int v) {
	u = find_set (id, u);
	v = find_set (id, v);
	if (u != v) {
		cn[id]--;
		if (sz[id][u] > sz[id][v])
			swap(&u, &v);
		sz[id][u] += sz[id][v];
		sz[id][v] = 0;
		par[id][v] = u;
	}
}

int main () {
	init (100);
	cout << find_set(10, 10) << endl;
	return 0;
}
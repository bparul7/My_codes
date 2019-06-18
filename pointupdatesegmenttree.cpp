//SEGMENT TREE
//POINT UPDATE AND RANGE QUERY
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
int n;
ll skill[100004];
ll seg[500003];

//Range of segment tree : low, high
//index of segment tree : i

//this function needs to be changed for deciding property of segment tree
ll update (int indx) {
	return (seg[2*indx] + seg[2*indx+1]);
}
//this function makes the leaf of the segment tree 
ll make (int indx) {
	return (skill[indx]);
}

void makeTree (int low, int high, int i) {
	if (low == high) {
		seg[i] = make (low);
		return;
	}
	if (low > high)
		return;
	int mid = low + (high - low ) / 2;
	makeTree (low, mid, 2*i);
	makeTree (mid+1, high, 2*i+1);
	seg[i] = update (i);
}

void pointUpdate (int low, int high, int i, ll val, int nodeno) {
	if (low > high)
		return;
	if (low == high) {
		seg[i] = val;
		skill[low] = val;
		//cout << seg[i] << ".." << endl;
		return;
	}
	int mid = low + (high - low ) / 2;
	if (nodeno <= mid)
		pointUpdate (low, mid, 2*i, val, nodeno);
	else
		pointUpdate (mid+1, high, 2*i+1, val, nodeno);
	seg[i] = update (i);
}

//l -> range left val ,r -> range right val
ll rangeQuery (int low, int high, int i, int l, int r) {
	if (l > r)
		return 0;
	if (low==l && high==r)
		return seg[i];
	int mid = low + (high - low ) / 2;
	ll a1 = rangeQuery (low, mid, 2*i, l, min(mid, r));
	ll a2 = rangeQuery (mid+1, high, 2*i+1, max(mid+1, l), r);
	return a1+a2;
}

void testCase() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> skill[i];

	// Make segment tree out of n nodes
	makeTree (1, n, 1);
	
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	testCase();
	return 0;
}
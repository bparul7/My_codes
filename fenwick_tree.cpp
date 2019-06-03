
// add(int indx, int val) : update element at indx with val
// query(int indx) : gives ans of [0, indx]

//0 based indexing
/*	0101
	0100
	0011
	0010
	0001
	0000
	make all trailing 1 , 0 to go down
	make first 0 from right 1 to go up
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 4;
const ll n = 1<<31;
int f_tree[N];
int query (int indx) {
	int ans = 0;
	while (indx >= 0) {
		ans += f_tree[indx];
		indx = (((indx)&(indx+1))-1);
	}
	return ans;
}

void add (int indx, int val) {
	while (indx <= n) {
		f_tree[indx] += val;
		indx = (indx|(indx+1));
	}
}

//1 based indexing 
// val = (FIRST BIT POSITION FROM RIGHT)
// make first 1 from right 0 to go down (indx - val)
// add position number of first 1 from right (int power of 2) to go up (indx + val)
int query (int indx) {
	int ans = 0;
	while (indx > 0) {
		ans += f_tree[indx];
		indx -= (((indx)&(-indx)));
	}
	return ans;
}

void add (int indx, int val) {
	while (indx <= n) {
		f_tree[indx] += val;
		indx += (((indx)&(-indx)));
	}
}

// 2D BIT
// For 2D Bit -> create BIT for each id 
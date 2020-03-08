//RAT IN MAZE
//given a matrix of 1 and 0
//u have to go from 1,1 to n,n , explore all possible paths

//0 -> blocking point, u cannot move further
//1 -> u can move L, R, U, D
//One point taken once in a path
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;
int vis[12][12];
int n, m;
int grid[12][12];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int IsRange (int x, int y) {
	if (x>=0 && x<n && y>=0 && y<m)
		return 1;
	return 0;
}

void go (int i, int j, int pos) {
	if (i==n-1 && j==m-1) {
		//we got an ans
		cout << "ANS:" << endl;
		for (int k=0; k<n; k++) {
			for (int l=0; l<m; l++)
				cout << vis[k][l] << " ";
			cout << endl;
		}
		return;
	}
	if (grid[i][j] == 0)
		return;
	//exploring all paths from a point
	for (int l=0; l<4; l++) {
		int xx = i+dx[l];
		int yy = j+dy[l];
		//helper function (It checks whether we are going to correct point or not)
		if (IsRange (xx, yy) && vis[xx][yy] == 0) {
			vis[xx][yy] = pos;   //going to path
			go (xx, yy, pos+1);
			vis[xx][yy] = 0;   //backtrack
		}
	}
}

void testCase() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cin >> grid[i][j];
	}	    
	vis[0][0] = 1;
	go (0, 0, 2);
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
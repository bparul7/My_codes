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
int n;

int SAFE (int ans[][12], int row, int col) {
	//check horizontally
	int cnt = 0;
	for (int j=1; j<=n; j++) {
		if (ans[row][j] == 1)
			cnt++;
	}
	if (cnt > 1)
		return 0;
	//check vertically
	cnt = 0;
	for (int j=1; j<=n; j++) {
		if (ans[j][col] == 1)
			cnt++;
	}
	if (cnt > 1)
		return 0;
	//check diadonally
	cnt = 0;
	int i=row;
	int j=col;
	while (i>0 && j>0) {
		if (ans[i][j] == 1)
			cnt++;
		i--;
		j--;
	}
	i = row+1;
	j = col+1;
	while (i<=n && j<=n) {
		if (ans[i][j] == 1)
			cnt++;
		i++;
		j++;
	}
	if (cnt > 1)
		return 0;
	//check next diagonal
	cnt = 0;
	i = row;
	j = col;
	while (i>0 && j<=n) {
		if (ans[i][j] == 1)
			cnt++;
		i--;
		j++;
	}
	i = row+1;
	j = col-1;
	while (i<=n && j>0) {
		if (ans[i][j] == 1)
			cnt++;
		i++;
		j--;
	}
	if (cnt > 1)
		return 0;
	return 1;
}

void go (int row, int ans[][12]) {
	if (row == n+1) {
		cout << "ANS:" << endl;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
		return;
	}
	for (int col=1; col<=n; col++) {
		ans[row][col] = 1;
		if (SAFE (ans, row, col)) {
			go (row+1, ans);
		}
		ans[row][col] = 0;
	}
}

void testCase() {
	cin >> n;
	int ans[12][12];
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++)
			ans[i][j] = 0;
	}
	go (1, ans);    
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
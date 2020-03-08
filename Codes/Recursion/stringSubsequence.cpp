//return all subsequences of a string
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
string s;
int n;
vector <string> ans;

void go (int indx, string sub) {
	if (indx == n) {
		ans.push_back (sub);
		return;
	}
	go (indx+1, sub+s[indx]);
	go (indx+1, sub);
}

void testCase() {
	cin >> s;
	n = s.size();
	//Using Recursion
	go (0, "");
	for (string ss : ans) {
		cout << ss << endl;
	}

	//Using Loop
	ans.clear();
	for (ll i=0; i<(1ll<<n); i++) {
		string vv = "";
		ll temp = i;
		for (int j=0; j<n; j++) {
			if (temp & (1ll<<j)) {
				vv += s[j];
			}
		}
		cout << vv << endl;
	}
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
//given a sequence, return all possible permutation of sequence
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
string seq;
int n;

//bottom up approach
vector <string> go (int indx) {
	if (indx == seq.size()-1) {
		vector <string> ans;
		string v = "";
		v += seq[indx];
		ans.push_back (v);
		return ans;
	}
	vector <string> ans = go (indx+1);
	//add character at indx
	vector <string> fans;
	for (int i=0; i<ans.size(); i++) {
		string v = ans[i];
		for (int j=0; j<=v.size(); j++) {
			//0-j and j-n
			string vv = v.substr (0, j) + seq[indx] + v.substr (j);
			fans.push_back (vv);
		}
	}
	return fans;
}

//Top down approach
// "" -> a -> ba, ab ->
void go (int indx, string output) {
	if (indx == seq.size()) {
		cout << output << endl;
		return;
	}
	for (int i=0; i<=output.size(); i++) {
		go (indx+1, output.substr(0,i)+seq[indx]+output.substr(i));
	}
}

void testCase() {
	cin >> seq;
	n = seq.size();
	//Using next_permutation
	string s = seq;
	do {
		cout << s << endl;
	}while (next_permutation (s.begin(), s.end()));

	//Using Recursion
	vector <string> ans = go (0);
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << endl;

	//Printing all permutations
	cout << "NO SPACE USING" << endl;
	go (0, "");
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
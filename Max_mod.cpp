//MAXIMISING MODULUS OF TWO NUMBERS IN AN ARRAY
//arr[i] % arr[j] = max and arr[i] >= arr[j]
//U can remove second condition accordingly

//arr[i]%arr[j] = max when arr[i] is close to arr[j] , ( arr[i]<arr[j] )
//  close to arr[j] means quotient = 0 ((arr[i] = arr[j]*0+r) <= arr[j]*1)
//  close to 2*arr[j] means quotient = 1
//  close to 3*arr[j] means quotient = 2

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
 
void testCase() {
	//Taking INPUT
    int n;
    cin >> n;
    set <int> s;
    for (int i=1; i<=n; i++) {
    	int v;
    	cin >> v;
    	s.insert (v);
    }
    vector <int> mx;
    auto it = s.begin();
    while (it != s.end()) {
    	mx.push_back (*it);
    	it++;
    }
    sort (mx.begin(), mx.end());
    int ans = 0;
    for (int j : mx) {
    	//fixing arr[j]
    	int st = 0;
    	//Traversing upper bound for arr[i] (arr[j]*mul)
    	for (int mul=2; mul*j<=(1000000+j); mul++) {
    		int indx = lower_bound (mx.begin()+st, mx.end(), mul*j) - mx.begin();
    		st = indx;
    		indx--;
    		if (indx >= 0 && indx < mx.size() && mx[indx]>j)
    			ans = max (ans, mx[indx]%j);
    	}
    }
    cout << ans << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
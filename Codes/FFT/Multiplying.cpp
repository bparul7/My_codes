//multilplying polynomials using FFT
#include <bits/stdc++.h>
using namespace std;

using base = complex<double>; 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;
double pi = acos(-1);

vector <base> FFT (vector <base> a) {
	int n = a.size();
	if (n == 1)
		return a;
	//find even coefficient and off coeff
	vector <base> even;
	vector <base> odd;
	for (int i=0; i<n; i++) {
		if (i&1)
			odd.push_back (a[i]);
		else
			even.push_back (a[i]);
	}
	even = FFT (even);
	odd = FFT (odd);
	//reconstruct ans;
	vector <base> ans(n);
	base w(double(1), double(0));
	double angle = 2*pi/n;
	base wn(cos(angle), sin(angle));
	for (int i=0; i<(n/2); i++) {
		ans[i] = even[i]+w*odd[i];
		ans[i+n/2] = even[i]-w*odd[i];
		w = w*wn;
	}
	return ans;
}

void testCase() {
	//2*n-1 -> power of 2
    //find point value form of first polynomial (2*n-1 points)
    //find point value form of second polynomial (2*n-1 points)
	int n1;
	cin >> n1;
	vector <base> p1;
	for (int i=0; i<n1; i++) {
		double v;
		cin >> v;
		base c(v, double(0));
		p1.push_back (c);
	}
	int n2;
	cin >> n2;
	vector <base> p2;
	for (int i=0; i<n2; i++) {
		double v;
		cin >> v;
		base c(v, double(0));
		p2.push_back (c);
	}
	//convert both to same degree
	int n3 = max (n1, n2);
	n3 = (2*n3-1);
	//convert n to power of 2
	int n = 2;
	while (n < n3) {
		n = n*2;
	}
	while (n1 < n) {
		base c(double(0), double(0));
		p1.push_back (c);
		n1++;
	}
	while (n2 < n) {
		base c(double(0), double(0));
		p2.push_back (c);
		n2++;
	}
	//find point value form for first polynomial
	vector <base> v1 = FFT (p1);
	vector <base> v2 = FFT (p2);
	for (int i=0; i<n; i++) {
		cout << (v1[i] * v2[i]) << endl;
	}
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
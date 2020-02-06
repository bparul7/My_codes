//FFT -> Convert coefficient value form to point value form
//2*x2 + 3*x + 1 -> 3 coefficients , so 3 y required

#include <bits/stdc++.h>
using namespace std;

using ll = int;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
#define endl "\n"
const ll mod = 1000000007;
const double pi = acos(-1);
//Takes input of coefficients and return corresponding y, for n complex nth root of unity

vector <complex<double>> omega;

complex<double> MUL (complex<double> a1, complex<double> a2) {
	double a = real (a1);
	double b = imag (a1);
	double p = real (a2);
	double q = imag (a2);
	complex <double> ans(a*p-b*q, a*q+b*p);
	return ans;
}

complex<double> ADD (complex<double> a1, complex<double> a2) {
	double a = real (a1);
	double b = imag (a1);
	double p = real (a2);
	double q = imag (a2);
	complex <double> ans(a+p, b+q);
	return ans;
}

void init (int n) {
	double angle = 2*pi/double(n);
	for (double i=0; i<=n; i++) {
		complex <double> c(cos(angle*i), sin(angle*i));
		omega.push_back (c);
	}
}

vector < complex<double> > FFT (vector <int> a) {
	int n = a.size();
	vector < complex<double> > ans(n);
	if (n == 0) {
		return ans;
	}
	if (n == 1) {
		//Linear polynomial
		complex<double> c(double(a[0]), double(0));
		ans[0] = (c);
		return ans;
	}
	//find even coefficients
	vector <int> ev;
	vector <int> od;
	for (int i=0; i<n; i++) {
		if (i&1)
			od.push_back (a[i]);
		else
			ev.push_back (a[i]);
	}
	vector <complex<double>> even = FFT (ev);
	vector <complex<double>> odd = FFT (od);
	//combine both to find ans
	//A(x) = Aeven(x^2) + x * Aodd(x^2)
	//w = e^(2*pi*i/n)
	complex<double> w(double(1), double(0));
	double angle = 2*pi/double(n);
	complex<double> w1(cos(angle), sin(angle));
	//run loop till n/2 because otherwise the value will be more approxed
	for (int i=0; i<(n/2); i++) {
		complex<double> l = (even[i]);
		complex<double> r = (odd[i]);
		ans[i] = l+w*r;
		ans[i+n/2] = l-w*r;
		//update w
		w = w*w1;
	}
	return ans;
}

void testCase() {
	//n should be a power of 2, otherwise add 0
	int n1;
	cin >> n1;
	vector <int> coeff;
	for (int i=0; i<n1; i++) {
		int val;
		cin >> val;
		coeff.push_back (val);
	}
	int n = 2;
	while (n < n1) {
		n = n * 2;
	}
	init(n);
	vector <complex<double>> ans = FFT (coeff);
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << endl;
}
 
int32_t main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
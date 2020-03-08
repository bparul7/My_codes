//given n numbers, each number occurs twice, except two numbers which occurs once
//Find those numbers

//APPROACH :
//Find xor of all numbers
//a ^ b = val
//Find first set bit in val (it will set in a , then it will not be set in b)
//xor all elements with set bit ( a1^a1^a) : It will give one number
//other no = val ^ one no
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
    int n;
    cin >> n;
    int arr[n+2];
    int val = 0;
    for (int i=0; i<n; i++) {
    	cin >> arr[i];
    	val = val ^ arr[i];
    }
    //find first set bit in val
    int vv = (val & (-val)); //It has bit set
    int a = 0;
    for (int i=0; i<n; i++) {
    	if (arr[i] & vv)
    		a ^= arr[i];
    }
    int b = val ^ a;
    cout << min (a, b) << " " << max (a, b) << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
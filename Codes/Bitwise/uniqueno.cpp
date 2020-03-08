//every number occurs thrice except one number which occurs once
//Find that number

//APPROACH:
//1. ones -> ith bit set if it occured (3*k+1) times
//2. two -> ith bit set if it occured (3*k+2) times
//3. three -> ith bit set if it occured (3*k) times

//We can make an array of count of bits, and then modulo cnt with 3 (o(n*32))
//We will calculate bits parallely
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
    int arr[n+1];
    for (int i=0; i<n; i++)
    	cin >> arr[i];
    int one = 0; //No bit occured 1 times
    int two = 0; //No bit occured 2 times

    //first time bit is set in one and not in two
    //second time bit is set in two nd unset in one
    //third time it is set in both and should be erased
    for (int i=0; i<n; i++) {
    	//The bits set in one and no => that no occured twice (should be set in two)
    	two = two | (one & arr[i]);
    	//remove bits from one which occured twice
    	one = one ^ arr[i];
    	//the bits set in (two & one) should be set in three
    	int three = (one & two);
    	//the bits set in three should not be set in one and two
    	//It is basically taking modulo with 3
    	//every third time a bit comes, that bit in one and two is made zero
    	one = one & (~three);
    	two = two & (~three);
    }
    cout << one << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
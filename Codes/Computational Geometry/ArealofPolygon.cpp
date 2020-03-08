//Area of POlygon -> Triangulation Method
//We will divide polygon into triangles and do vector summation of area
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

class pt {
	public:
		db x;
		db y;
};

int n; //no of points
vector <pt> points; //coordinates in clockwise order

db AreaOfTriangle (pt p1, pt p2, pt p3) {
	p2.x = (p2.x - p1.x);
	p2.y = (p2.y - p1.y);
	p3.x = (p3.x - p1.x);
	p3.y = (p3.y - p1.y);
	//p2 -> vector from p1 to p2
	//p3 -> vector from p1 to p3
	db ans = (p2.x * p3.y - p2.y * p3.x);
	return ans;
}

db AreaOfPolygon () {
	db ans = 0;
	//divide thepolygon into triangles and then find vector area
	// 0point to (i and i+1)
	for (int i=1; i<n-1; i++) {
		ans = ans + AreaOfTriangle (points[0], points[i], points[i+1]);
	}
	ans = ans / 2;
	ans = abs (ans);
	return ans;
}

void testCase() {
    cin >> n;
    for (int i=0; i<n; i++) {
    	pt p1;
    	cin >> p1.x >> p1.y;
    	points.push_back (p1);
    }
    cout << AreaOfPolygon () << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
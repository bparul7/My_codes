//CONVEX HULL : Given n points in 2D plane, find minimum number of points taken, so that all points are inside the
//boundary formed
//Finding boundary for the collection of points (boundary formed with minimum number of points)
//JARVIS THEOREM 
//O(n^2)
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
//#define endl "\n"
const ll mod = 1000000007;

class point {
public:
	db x, y;
};

int n;
vector <point> Points;
vector <point> convexHull;

bool isChange (point p, point q, point r) {
	//find pq cross qr
	p.x = -(p.x - q.x);
	p.y = -(p.y - q.y);
	r.x = r.x - q.x;
	r.y = r.y - q.y;
	db val = (p.x * r.y - p.y * r.x);
	// val > 0 => r is strictly outside
	if (val > 0)
		return 1;
	return 0;
}

void Convex () {
	int left = 0;
	//find leftmost point
	for (int i=0; i<Points.size(); i++) {
		if (Points[i].x < Points[left].x)
			left = i;
	}
	int p = left;
	do {
		convexHull.push_back (Points[p]);
		int q = (p+1)%n; //take nextmost point for q
		//for each r : pq cross qr >0 (for change)
		for (int i=0; i<n; i++) {
			if (isChange (Points[p], Points[q], Points[i])) {
				q = i;
			}
		}
		//we got the leftmost boundary
		p = q;
	} while (p != left);
}

void testCase() {
    cin >> n;
    for (int i=0; i<n; i++) {
    	point p;
    	cin >> p.x >> p.y;
    	Points.push_back (p);
    }
    Convex ();
    for (int i=0; i<convexHull.size(); i++) {
    	cout << convexHull[i].x << " " << convexHull[i].y << endl;
    }
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
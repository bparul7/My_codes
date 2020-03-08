//finding intersection points of two line segments
//given (x1, y1) and (x2, y2)
//given (x3, y3) and (x4, y4)
//Find intersection points of two lines
//Then check the point should lie on line segments x >= min (x1, x2) and y <= max (y1, y2)
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

class lineSegment {
public:
	db x1;
	db y1;
	db x2;
	db y2;
	db A, B, C;
};

class pt {
public:
	db x, y;
};

void RepresentLine (lineSegment &l) {
	l.A = (l.y2-l.y1);
	l.B = (l.x1-l.x2);
	l.C = (l.x1*(l.y2-l.y1) + l.y1*(l.x1-l.x2));
}

int FindIntersection (lineSegment l1, lineSegment l2, pt &p) {
	// Ax+By=C
	// Px+Qr=D
	// x = (- BD + CQ) / (AQ - PB)
	//If determinant of coefficients = 0 => parallel, else find
	db det = l1.A * l2.B - l1.B * l2.A;
	if (det == 0) {
		return 0;
	}
	else {
		p.x = (l1.C*l2.B - l1.B*l2.C) / (det);
		p.y = (l1.C - l1.A*p.x) / l1.B;
		return 1;
	}
}

int lieOnSegment (lineSegment l, pt p) {
	if (p.x >= min (l.x1, l.x2) && p.x <= max (l.x1, l.x2) && p.y >= min (l.y1, l.y2) && p.y <= max (l.y1, l.y2))
		return 1;
	return 0;
}

void testCase() {
	lineSegment l1, l2;
	cin >> l1.x1 >> l1.y1;
	cin >> l1.x2 >> l1.y2;
	cin >> l2.x1 >> l2.y1;
	cin >> l2.x2 >> l2.y2;
	//Represent linesegment in line equation : Ax + By = C
	RepresentLine (l1);
	RepresentLine (l2); 
	//Find Intersection Point of two lines
	pt p;
	int st = FindIntersection (l1, l2, p);
	if (st == 0) {
		cout << "Parallel Lines" << endl;
	}
	else {
		cout << "Intersecting Lines" << endl;
		cout << p.x << " " << p.y << endl;
	}
	//Check if intersection point lie on line segments
	if (lieOnSegment (l1, p) && lieOnSegment (l2, p)) {
		cout << "Intersection Point is point of Intersection of Line Segments" << endl;
	}
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
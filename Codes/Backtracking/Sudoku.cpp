//given a 9*9 sudoku, u have to fill the sudoku
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
string sud[10];
string ans[10];
int flg;

void find_unfilled (int &row, int &col) {
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			if (sud[i][j] == '0') {
				row = i;
				col = j;
				return;
			}
		}
	}
	return;
}

int Issafe (int row, int col) {
	char ch = sud[row][col];
	//check horizontally
	int cnt = 0;
	for (int i=0; i<9; i++) {
		if (sud[row][i] == ch)
			cnt++;
	}
	if (cnt > 1)
		return 0;
	//check vertically
	cnt = 0;
	for (int i=0; i<9; i++) {
		if (sud[i][col] == ch)
			cnt++;
	}
	if (cnt > 1)
		return 0;
	//check in 3*3 box
	for (int i=0; i<9; i+=3) {
		for (int j=0; j<9; j+=3) {
			//i - i+2 and j - j+2
			if (row>=i && row<=(i+2) && col>=j && col<=(j+2)) {
				cnt = 0;
				for (int k=i; k<i+3; k++) {
					for (int l=j; l<j+3; l++) {
						if (sud[k][l] == ch)
							cnt++;
					}
				}
				if (cnt > 1)
					return 0;
			}
		}
	}
	return 1;
}

//find first unfilled position in sudoku and then explore all possible path (1-9)
//go to that path which is filled safely

void go () {
	//find first unfilled position
	int row = -1;
	int col = -1;
	find_unfilled (row, col);
	if (row == -1) {
		//filled
		for (int i=0; i<9; i++)
			ans[i] = sud[i];
		flg = 1;
		return;
	}
	for (char ch='1'; ch<='9'; ch++) {
		sud[row][col] = ch;
		if (Issafe (row, col)) {
			go ();
		}
		sud[row][col] = '0';
	}
}

void testCase() {
	for (int i=0; i<9; i++)
		cin >> sud[i];
	go ();  
	if (flg == 0) {
		cout << "NO SOLUTION" << endl;
		return;
	}
	for (int i=0; i<9; i++)
		cout << ans[i] << endl;  
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
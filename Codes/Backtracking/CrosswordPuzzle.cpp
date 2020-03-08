//given a crossword, with + and - and a list of words
//Place all words on crossword , only - can be replaced
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
string cross[12];
int vis[101];
vector <string> words;

void find_first (int &row, int &col) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (cross[i][j] == '-') {
				row = i;
				col = j;
				return;
			}
		}
	}
	return;
}
//check first empty - and try to place word from there in all possible directions
//If u can place , explore further
//backtrack if u donot find a soln

bool can_horizontal (int row, int col, string word) {
	int i=0;
	while (col<10 && i<word.size()) {
		if (cross[row][col] == word[i] || cross[row][col] == '-') {
			col++;
			i++;
		}
		else {
			return false;
		}
	}
	if (i==word.size())
		return true;
	return false;
}

void put_horizontal (int row, int col, string word, int change[][12]) {
	int i=0;
	while (col<10 && i<word.size()) {
		if (cross[row][col] == '-')
			change[row][col] = 1;
		cross[row][col] = word[i];
		i++;
		col++;
	}
}

void unput_horizontal (int row, int col, string word, int change[][12]) {
	int i=0;
	while (col<10 && i<word.size()) {
		if (change[row][col])
			cross[row][col] = '-';
		change[row][col] = 0;
		i++;
		col++;
	}
}

bool can_vertical (int row, int col, string word) {
	int i=0;
	while (row<10 && i<word.size()) {
		if (cross[row][col] == word[i] || cross[row][col] == '-') {
			row++;
			i++;
		}
		else {
			return false;
		}
	}
	if (i==word.size())
		return true;
	return false;
}

void put_vertical (int row, int col, string word, int change[][12]) {
	int i=0;
	while (row<10 && i<word.size()) {
		if (cross[row][col] == '-')
			change[row][col] = 1;
		cross[row][col] = word[i];
		i++;
		row++;
	}
}

void unput_vertical (int row, int col, string word, int change[][12]) {
	int i=0;
	while (row<10 && i<word.size()) {
		if (change[row][col])
			cross[row][col] = '-';
		change[row][col] = 0;
		i++;
		row++;
	}
}

bool can_leftdiagonal (int row, int col, string word) {
	int i=0;
	while (col>=0 && row<10 && i<word.size()) {
		if (cross[row][col] == word[i] || cross[row][col] == '-') {
			col--;
			row++;
			i++;
		}
		else {
			return false;
		}
	}
	if (i==word.size())
		return true;
	return false;
}

void put_leftdiagonal (int row, int col, string word, int change[][12]) {
	int i=0;
	while (col>=0 && row<10 && i<word.size()) {
		if (cross[row][col] == '-')
			change[row][col] = 1;
		cross[row][col] = word[i];
		i++;
		col--;
		row++;
	}
}

void unput_leftdiagonal (int row, int col, string word, int change[][12]) {
	int i=0;
	while (col>=0 && row<10 && i<word.size()) {
		if (change[row][col])
			cross[row][col] = '-';
		change[row][col] = 0;
		i++;
		col--;
		row++;
	}
}

bool can_rightdiagonal (int row, int col, string word) {
	int i=0;
	while (col<10 && row<10 && i<word.size()) {
		if (cross[row][col] == word[i] || cross[row][col] == '-') {
			col++;
			row++;
			i++;
		}
		else {
			return false;
		}
	}
	if (i==word.size())
		return true;
	return false;
}

void put_rightdiagonal (int row, int col, string word, int change[][12]) {
	int i=0;
	while (col<10 && row<10 && i<word.size()) {
		if (cross[row][col] == '-')
			change[row][col] = 1;
		cross[row][col] = word[i];
		i++;
		col++;
		row++;
	}
}

void unput_rightdiagonal (int row, int col, string word, int change[][12]) {
	int i=0;
	while (col<10 && row<10 && i<word.size()) {
		if (change[row][col])
			cross[row][col] = '-';
		change[row][col] = 0;
		i++;
		col++;
		row++;
	}
}

bool go () {
	int row, col;
	row = col = -1;
	find_first (row, col);
	if (row == -1) {
		return true;
	}
	//try to put non visited words in all directions
	for (row=0; row<10; row++) {
		for (col=0;col<10; col++) {
			if (cross[row][col] == '+')
				continue;
			for (int i=0; i<words.size(); i++) {
				if (vis[i] == 1)
					continue;
				string word = words[i];
				//put horizontally
				int change[12][12];
				for (int l=0; l<10; l++) {
					for (int r=0; r<10; r++) {
						change[l][r] = 0;
					}
				}
				if (can_horizontal (row, col, word)) {
					put_horizontal (row, col, word, change);
					vis[i] = 1;
					if (go ())
						return true;
					vis[i] = 0;
					unput_horizontal (row, col, word, change);
				}
				//put vertically
				if (can_vertical (row, col, word)) {
					put_vertical (row, col, word, change);
					vis[i] = 1;
					if (go ())
						return true;
					vis[i] = 0;
					unput_vertical (row, col, word, change);
				}
				//put left diagonal
				if (can_leftdiagonal (row, col, word)) {
					put_leftdiagonal (row, col, word, change);
					vis[i] = 1;
					if (go ())
						return true;
					vis[i] = 0;
					unput_leftdiagonal (row, col, word, change);
				}
				//put right diagonal
				if (can_rightdiagonal (row, col, word)) {
					put_rightdiagonal (row, col, word, change);
					vis[i] = 1;
					if (go ())
						return true;
					vis[i] = 0;
					unput_rightdiagonal (row, col, word, change);
				}
			}
		}
	}
	return false;
}

void testCase() {
	for (int i=0; i<10; i++)
		cin >> cross[i];
	string word;
	cin >> word;
	int i=0;
	string v = "";
	while (i<word.size()) {
		v += word[i];
		i++;
		if (i==word.size() || word[i]==';') {
			words.push_back (v);
			v = "";
			i++;
		}
	}
	bool st = go ();
	if (st == true) {
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++)
				cout << cross[i][j];
			cout << endl;
		}
	}   
	else {
		cout << "NOT POSSIBLE" << endl;
	} 
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
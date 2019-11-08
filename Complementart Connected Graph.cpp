/*In Normal graph questions, we are given the edges than are needed in the graph. In these type of questions we are given opposite information about the graph (COMPLEMENTARY GRAPH).*/ 
/*E.G. : Given a fully connected graph, and the no of edges with are not in the graph. We have to find number of connected components in the graph.*/
//LINK: https://codeforces.com/contest/920/problem/E

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
int n, m;
vector <set<int>> g(200005); //stores the complementary information given
set <int> unvisited;         //stores the vertices which has not been added to any component
 
int bfs (int indx) {
	//for each u in queue , we will traverse the unvisited vertices and add that vertex to queue which doesnot form edge with u
    queue <int> q;
    int cnt=0;  //returns size of connected component
    q.push (indx);
    unvisited.erase (unvisited.find(indx));
    while (!q.empty()) {
        int v = q.front();
        cnt++;
        q.pop();
        auto it = unvisited.begin();
        vector <int> vv;
        while (it != unvisited.end()) {
            int v1 = *it;
            if (g[v].find(v1) == g[v].end()) {
                vv.push_back (v1);
                q.push(v1);
            }
            it++;
        }
        for (int v1: vv) {
            unvisited.erase (unvisited.find(v1));
        }
    }
    return cnt;
}
 
void testCase() {
    //int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert (v);
        g[v].insert (u);
    }
    for (int i=1; i<=n; i++)
        unvisited.insert (i);
    vector <int> sz;
    for (int i=1; i<=n; i++) {
    	//if the vertex is still unvisited , find connected component with it
        if (unvisited.find(i) != unvisited.end()) {
            sz.push_back (bfs (i));
        }
    }
    sort (sz.begin(), sz.end());
    cout << sz.size() << endl;
    for (int v : sz) {
    	cout << v << " ";
    }
    cout << endl;
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}
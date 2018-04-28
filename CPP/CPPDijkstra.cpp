#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF 1<<29
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back

#if DEBUG
#define _DEBUG(x) cout<<#x<<": "<<x<<endl
#define _DDEBUG(x,y) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl
#else
#define _DEBUG(x) ;
#define _DDEBUG(x,y) ;
#endif

#define ll long long
#define ull unsigned long long
#define MOD 1000000007

/** FOR VECTOR DEBUG */
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    if ( !v.empty() ) {
        out << '[';
        copy (v.begin(), v.end(), ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}
const int max_v = 100010;
const ll infinite = 1000'0000'0000'0000;

struct edge { int to, cost; };
using P = pair<int, int>;

int V; // vertex
vector<edge> G[max_v + 5]; // cost(if not exist, this value is INF)
ll d[max_v]; // distance

void dijkstra(int s) {
    // we can get small order first due to point greater
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, infinite);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }

        for(int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.precision(16);

    int n;
    cin >> n;

    int a, b, c;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        edge e1 = {b, c};
        edge e2 = {a, c};
        G[a].push_back(e1);
        G[b].push_back(e2);
    }

    int q, k;
    cin >> q >> k;
    V = n + 1;
    dijkstra(k);

    int x, y;
    for(int i = 0; i < q; i++) {
        cin >> x >> y;
#if DEBUG
        cout << "** RESULT **" << endl; // debug
        _DDEBUG(x, y);
        _DDEBUG(d[x], d[y]);
#endif
        cout << d[x] + d[y] << endl;
   }
	return 0;
}


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

// refer: http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=ALDS1_1_B
int gcd(int a, int b) {
    if(a < b) swap(a, b);
    while(b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int arrgcd(int *x, int length) {
    int t = x[0];
    FOR(i, 1, length) t = gcd(t, x[i]);
    return t;
}

int vecgcd(vector<int> x){
    int t = x[0];
    FOR(i, 1, x.size()) t = gcd(t, x[i]);
    return t;
}

int lcm(int a, int b) {
    if(a == 0 || b == 0) {
        cout << "Error" << endl;
        return 0;
    }

    return (a * b / gcd(a, b));
}

int arrlcm(int *x, int length) {
    int t = x[0];
    FOR(i, 1, length) t = lcm(t, x[i]);
    return t;
}

int veclcm(vector<int> x){
    int t = x[0];
    FOR(i, 1, x.size()) t = lcm(t, x[i]);
    return t;
}

ll llgcd(ll a, ll b) {
    if(a < b) swap(a, b);
    while(b > 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void testMethod() {
    _DEBUG(gcd(3, 5));
    _DEBUG(gcd(15, 55));
    _DEBUG(gcd(4, 8));
    _DEBUG(llgcd(1234567890123456, 1000000007));
    _DEBUG(lcm(3, 5));

    // arr test
    {
        int x[4] = {2, 3, 4, 5};
        _DEBUG(arrgcd(x, ALEN(x)));
        _DEBUG(arrlcm(x, ALEN(x)));
        int y[3] = {8, 12, 16};
        _DEBUG(arrgcd(y, ALEN(y)));
        _DEBUG(arrlcm(y, ALEN(y)));
    }

    // vector test
    {
        int x[4] = {3, 5, 7, 9};
        vector<int> vx(x, x+ALEN(x));
        _DEBUG(vecgcd(vx));
        _DEBUG(veclcm(vx));
        int y[3] = {15, 20, 25};
        vector<int> vy(y, y+ALEN(y));
        _DEBUG(vecgcd(vy));
        _DEBUG(veclcm(vy));
    }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.precision(16);

	testMethod();
	return 0;
}

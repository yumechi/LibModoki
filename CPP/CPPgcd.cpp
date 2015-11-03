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
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF 1<<30
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

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
    DEBUG(gcd(3, 5));
    DEBUG(gcd(15, 55));
    DEBUG(gcd(4, 8));
    DEBUG(llgcd(1234567890123456, 1000000007));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(16);

  testMethod();
  return 0;
}

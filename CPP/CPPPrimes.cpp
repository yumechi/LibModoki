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
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<int> prime_factorization(int n) {
	vector<int> ret;
	FOR(i, 2, (int)(sqrt(n) + 2)) {
		while(n % i == 0) {
			n /= i;
			ret.pb(i);
		}
	}
	if(n > 1) ret.pb(n);
	return ret;
}

map<int, int> prime_counter(int n) {
map<int, int> ret;
	FOR(i, 2, (int)(sqrt(n) + 2)) {
		while(n % i == 0) {
			n /= i;
			if(ret.find(i) == ret.end()) {
				ret[i] = 1;
			} else {
				ret[i]++;
			}
		}
	}
	if(n > 1) ret[n] = 1;
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.precision(16);

	map<int, int> pcmap = prime_counter(1341398);
	for(auto elem : pcmap) {
		cout << "num: " << elem.first << "  second: " << elem.second << endl;
	}

	vector<int> pflist = prime_factorization(20101010);
	for(auto elem : pflist) {
		cout << "num : " << elem << endl;
	}

	return 0;
}

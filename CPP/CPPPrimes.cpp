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

vector<int> getPrimes(int n) {
	vector<int> ret;

	// errro check
	if(n <= 0) {
		cout << "can use this method negative number: getPrime " << n << endl;
		return ret;
	}

	FOR(i, 2, n) {
		bool flag = true;
		for(auto prime : ret) {
			if(i % prime == 0) {
				flag = false;
				break;
			}
		}

		if(flag) ret.pb(i);
	}

	return ret;
}

int* getEratosthenes(int *ret, int n) {
	REP(i, n) ret[i] = 1;

	ret[0] = ret[1] = 0;
	int range = sqrt(n) + 1;
	FOR(i, 2, range) {
		if(ret[i] == 1) {
			for(int j = i * 2; j < n; j += i) {
				ret[j] = 0;
			}
		}
	}

	return ret;
}

/********************
 **  TEST METHOD   **
*********************/

void counterTest() {
	map<int, int> pcmap = prime_counter(1341398);
	for(auto elem : pcmap) {
		cout << "num: " << elem.first << "  second: " << elem.second << endl;
	}
}

void factorizationTest() {
	vector<int> pflist = prime_factorization(20101010);
	for(auto elem : pflist) {
		cout << "num : " << elem << endl;
	}
}

void primesTest() {
	vector<int> primeList = getPrimes(105);
	for(auto elem : primeList) {
		cout << "num : " << elem << endl;
	}
}

void eratosthenesTest() {
	int num = 1004;
	int arr[num];
	int *primeList = getEratosthenes(arr, num);
	REP(i, num) {
		if(primeList[i] == 1) cout << "Primes: " << i << endl;
	}
}

void test() {
	// counterTest();
	// factorizationTest();
	// primesTest();
	eratosthenesTest();
}


/********************
 **  MAIN METHOD   **
*********************/

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.precision(16);

	test();
	return 0;
}

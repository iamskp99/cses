#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define vi vector<int>
#define mii map<int,int>
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll MOD = 1000000007;


void solve() {
	string s;
	cin >> s;
	int ans = -1;
	string prev = ".";
	int cnt = 0;
	string x;
	for (int i = 0; i < s.length(); i++) {
		x = s[i];
		if (prev == x) {
			cnt = cnt + 1;
		}
		else {
			ans = max(ans, cnt);
			cnt = 1;
			prev = x;
		}
	}
	ans = max(ans, cnt);
	cout << ans;
}


int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	// cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
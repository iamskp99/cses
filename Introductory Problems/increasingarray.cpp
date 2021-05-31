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
	ll temp, ans, i, prev, n;
	ll arr[200001];
	cin >> n;
	i = 0;
	while (i < n) {
		cin >> arr[i];
		i = i + 1;
	}
	prev = -1;
	i = 0;
	ans = 0;
	while (i < n) {
		if (i == 0) {
			prev = arr[i];
		}
		temp = arr[i];
		if (temp < prev) {
			ans += abs(prev - temp);
			prev = temp + abs(prev - temp);
			i = i + 1;
			continue;
		}
		prev = temp;
		i = i + 1;
	}

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
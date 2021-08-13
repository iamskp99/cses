#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define gcd(x,y) __gcd(x,y)
#define tostr(x) to_string(x)
#define vi vector<int>
#define mii map<int,int>
#define umap unordered_map
#define ff first
#define ss second
#define INF 1e18
#define sastaINF 1e9
#define nline "\n"
#define PI 3.141592653589793238462
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

/////////////////////////// Functions /////////////////////////////
bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
	return (a.second < b.second);
}

///////////////////////////////////////////////////////////////////
bool sortbysec1(const pair<ll, pair<ll, ll>> &a,
                const pair<ll, pair<ll, ll>> &b)
{
	return (a.second.first < b.second.first);
}

vector<pair<ll, pair<ll, ll>>> arr;
vector<ll> ep;
ll n;
ll dp[200001];

ll rec(ll i) {
	if (i < 0) {
		return 0;
	}

	if (dp[i] != -1) {
		return dp[i];
	}
	ll ans = rec(i - 1);
	ll now = arr[i].second.second;
	ll start = arr[i].first; //Binary Search to find the element index which has
	//ending point less than starting point at current index.
	ll ind = upper_bound(ep.begin(), ep.end(), start - 1) - ep.begin() - 1;
	if (ind != -1) {
		ans = max(ans, now + rec(ind));
	}
	else {
		ans = max(ans, now);
	}
	dp[i] = ans;
	return dp[i];
}

void solve() {
	ll a, b, c, i;
	cin >> n;
	i = 0;
	while (i < n) {
		cin >> a >> b >> c;
		arr.pb(make_pair(a, make_pair(b, c)));
		ep.pb(b);
		i = i + 1;
	}
	sort(ep.begin(), ep.end());
	sort(arr.begin(), arr.end(), sortbysec1);
	i = 0;
	while (i < n) {
		dp[i] = -1;
		i = i + 1;
	}
	cout << rec(n - 1) << nline;
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
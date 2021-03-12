#include <iostream>
#include <bits/stdc++.h>
#define ll int
#define pb(x) push_back(x)
using namespace std;

ll dp[501][501];

ll rec(ll a, ll b) {
    if (dp[a][b] != -1) {
        return dp[a][b];
    }

    if (a == b) {
        return 0;
    }
    if (a == 1 || b == 1) {
        return a - 1 + b - 1;
    }

    ll ans = 1e5;
    ll i = 1;
    while (i < a) {
        ans = min(ans, 1 + rec(a - i, b) + rec(i, b));
        i = i + 1;
    }
    i = 1;
    while (i < b) {
        ans = min(ans, 1 + rec(a, b - i) + rec(a, i));
        i = i + 1;
    }
    dp[a][b] = ans;
    return dp[a][b];
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll i = 0;
    while (i < a + 1) {
        ll j = 0;
        while (j < b + 1) {
            dp[i][j] = -1;
            j = j + 1;
        }
        i = i + 1;
    }
    cout << rec(a, b) << "\n";
    return 0;
}
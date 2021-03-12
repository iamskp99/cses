//Edit Distance
#include <iostream>
#include <bits/stdc++.h>
#define ll int
#define pb(x) push_back(x)
using namespace std;
ll dp[5001][5001];
string s1;
string s2;
ll n,x;
ll rec(ll i,ll j,string &s1,string &s2){
    if (s1.length() == i || s2.length() == j){
        return max((ll)s1.length()-i,(ll)s2.length()-j);
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans;
    if(s1[i] == s2[j]){
         ans = rec(i+1,j+1,s1,s2);
    }
    else{
    ll op1 = 1+rec(i+1,j+1,s1,s2);
    ll op2 = 1+rec(i+1,j,s1,s2);
    ll op3 = 1+rec(i,j+1,s1,s2);
    ans = min(op1,min(op2,op3));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
 
int main(){
    cin>>s1;
    cin>>s2;
    ll i = 0;
    while(i < s1.length()){
        ll j = 0;
        while(j < s2.length()){
                dp[i][j] = -1;
                j = j+1;
        }
        i = i+1;
    }
    cout<<rec(0,0,s1,s2)<<"\n";
return 0;
}
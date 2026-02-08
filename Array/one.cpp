#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

bool solve1(vector<ll> &v1, vector<ll> &v2, ll x, ll i, bool p){
    if(i == v1.size()) return p == 0;

    bool ok = false;
    if(x <= v1[i]) ok |= solve1(v1, v2, v1[i], i+1, p);
    if(x <= v2[i]) ok |= solve1(v1, v2, v2[i], i+1, p);

    if(p){
        if(x <= v1[i] && v1[i] <= v2[i])
            ok |= solve1(v1, v2, v2[i], i+1, 0);
        if(x <= v2[i] && v2[i] <= v1[i])
            ok |= solve1(v1, v2, v1[i], i+1, 0);
    }
    return ok;
}

void solve(){   
    ll n;
    cin >> n;

    vector<ll> v1(n), v2(n);
    for(ll &x : v1) cin >> x;
    for(ll &x : v2) cin >> x;

    cout << (solve1(v1, v2, 0, 0, 1) ? "Yes" : "No") << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
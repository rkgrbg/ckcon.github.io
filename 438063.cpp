#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void solve();

int main(){
    int T = 1;
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

void solve(){
    ll i, j, k, l = 0, i1, i2, t1, t2;
    ll n;
    cin >> n;
    vector<ll> v(n), ps(2*n+1, 0);
    for(i=0;i<n;i++) cin >> v[i];
    for(i=1;i<=2*n;i++){
        ps[i] = ps[i-1] + v[(i-1)%n];
    }
    
    unordered_map<ll, deque<ll>> mp;
    for(i=1;i<2*n+1;i++){
        if(i<n && !ps[i]){
            cout << "YES";
            return;
        }
        if(!mp[ps[i]].empty() && ps[i-1] != ps[i]){
            while(!mp[ps[i]].empty() && mp[ps[i]].front()<= i-n) mp[ps[i]].pop_front();
            if(!mp[ps[i]].empty()){
                cout << "YES";
                return;
            }
        }
        if(i<2*n && ps[i] == ps[i-1] && ps[i] == ps[i+1]){
            cout << "YES";
            return;
        }
        mp[ps[i]].push_back(i);
    }

    cout << "NO";
    return;
}
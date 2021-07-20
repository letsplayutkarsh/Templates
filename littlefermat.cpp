#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll MOD = 1e9+7;

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = a * 1ll * a % MOD;
            p /= 2;
        }
        else {
            res = res * 1ll * a % MOD;
            p--;
        }
    }
    return res;
}

ll mod_divide(ll a, ll b) {
    return ((a%MOD)*(fast_pow(b,MOD-2)%MOD))%MOD;
}

int main(){
    cout<<mod_divide(27,2);
}

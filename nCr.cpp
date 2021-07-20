int fac[20005],inv[20005];

ll fast_pow(ll a, ll p=MOD-2) {
    ll res = 1;
    while (p>0) {
        if (p&1) {
            res=(a*(res%MOD))%MOD;
        }
        a=(a*(a%MOD))%MOD;
        p>>=1;
    }
    return res;
}

void factorials(ll n){
    fac[0] = 1;
    ll k=0;
    for(k=1; k<n; k++){
        fac[k] = (fac[k - 1] * k) % MOD;
    }
    k--;
    inv[k]=fast_pow(fac[k],MOD-2);
    for(k--; k>=0; k--){
        inv[k]=((inv[k+1]%MOD)*(k+1))%MOD;
    }
}

ll nCr(ll n, ll r){
    if(r>n || n<0 || r<0){
        return 0;
    }
    return ((fac[n]*inv[r]%MOD) * (inv[n-r]%MOD))%MOD;
}

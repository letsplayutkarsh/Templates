#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
vector<int> primes;
bool prime[MAXN];

void addprimes(){
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p < MAXN; p++){
        if (prime[p] == true){
            for (int i = p * p; i < MAXN; i += p)
                prime[i] = false;
        }
    }
    primes.push_back(2);
    for (int p = 3; p < MAXN; p+=2)
        if (prime[p])
            primes.push_back(p);
}

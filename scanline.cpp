// https://codeforces.com/contest/1249/problem/D2

#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace  __gnu_pbds;
using namespace std::chrono;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define ll int
#define ull  unsigned long long
#define lcm(a,b) a*b/__gcd(a,b)
#define gcd(a,b) __gcd(a,b)

//vectors & pairs
#define all(a) a.begin(),a.end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define vi  vector<int>
#define vll  vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define vp vector<pair<int,int>>
#define mp make_pair
#define sortVA(a) sort(a.begin(),a.end())
#define sortVD(a) sort(a.rbegin(),a.rend())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//pair
#define f first
#define s second

//constants
double PIE = 3.1415926536;
int MOD = 1000000007;
int MAX = (1e9 + 5);
int MIN = -(1e9 + 5);
#define endl "\n"

//loop
#define ff(i,s,e)  for(i=(int)s; i< (int)e; i++)
#define rff(i,s,e) for(i=(int)e; i>=(int)s; i--)
#define vff(a) for(auto &x: a)
#define read(a) for(auto &x: a) cin>>x;
#define put(a) for(auto &x: a) cout<<x<<" "; cout<<endl;;

//debug
#define deb1(a)             cout<<#a<<"="<<a<<endl;
#define deb2(a,b)           cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;
#define deb3(a,b,c)         cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<endl;
#define deb4(a,b,c,d)       cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl;
#define deb5(a,b,c,d,e)     cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl;
#define deb6(a,b,c,d,e,f)   cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl;

template<typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;


// global variables
ll i,j;

//helper functions
ll ceil_div(ll x, ll y){
    return (x + y - 1) / y;
}

// struct interval{
//     int p;
//     int t;
//     int ind;
//
//     bool operator()(const interval& a, const interval& b){
//         return (a.p < b.p);
//     }
// };

//coding starts here
void test_cases(){

    int n,k;
    cin>>n>>k;

    vvi scanline(2*n, vi(3));
    map<int,int> endpoint;
    for(int i=0; i<n; i++){
        int L,R;
        cin>>L>>R;
        endpoint[i+1] = R;
        scanline[2*i] = {L, 0, i+1};
        scanline[2*i+1] = {R, 1, i+1};
    }

    sortVA(scanline);
    multiset<pair<int,int>, greater<pair<int,int>>> st;

    vi ans;
    for(int i=0; i<2*n; i++){
        if(scanline[i][1] == 0){
            st.insert(mp(endpoint[scanline[i][2]], scanline[i][2]));
        }
        if((int)st.size() > k){
            auto it = st.begin();
            ans.pb(it->s);
            st.erase(it);
        }
        if(scanline[i][1] == 1){
            auto it = st.find(mp(scanline[i][0], scanline[i][2]));
            if(it!=st.end()){
                st.erase(it);
            }
        }
    }

    cout<<ans.size()<<endl;
    put(ans);

    return;
}


int32_t main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    while(T--){
        test_cases();
    }
    return 0;
}

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

#define int long long
#define ll long long
#define lcm(a,b) a*b/__gcd(a,b)
#define gcd(a,b) __gcd(a,b)

//vectors & pairs
#define all(a) a.begin(),a.end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define vi  vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define mp make_pair
#define sortVA(a) sort(a.begin(),a.end())
#define sortVD(a) sort(a.rbegin(),a.rend())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//pair
#define f first
#define s second

//constants
int MOD = 1000000007;
int INF = (1e18 + 5);
#define endl "\n"

//loop
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


//helper functions
ll ceil_div(ll x, ll y){
    return (x + y - 1) / y;
}
struct query{
    int l;
    int r;
    int i;
};

int block = 550;
const int nax = 3e5 + 5;
vi a(nax),ans(nax);
vector<query> Q;
int n,q,cnt=0;


bool cmp(query a, query b){
    if(a.l/block != b.l/block){
        return a.l/block < b.l/block;
    }
    return a.r < b.r;
}

void add(int i){

}

void rem(int i){

}

//coding starts here
void test_cases(){

    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<q; i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        query temp;
        temp.l = l;
        temp.r = r;
        temp.i = i;
        Q.pb(temp);
    }

    sort(all(Q), cmp);

    int low = 0, high = -1;
    for(int i=0; i<q; i++){
        int L = Q[i].l;
        int R = Q[i].r;
        int ind = Q[i].i;

        while(low > L){
            low--;
            add(low);
        }
        while(high < R){
            high++;
            add(high);
        }

        while(low < L){
            rem(low);
            low++;
        }
        while(high > R){
            rem(high);
            high--;
        }

        ans[ind] = cnt;
    }


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

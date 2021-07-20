#include <bits/stdc++.h>
using namespace std;

#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)

const int Nax = 1e5 + 5;
vector<int> seg(4*Nax);
vector<int> lazy(4*Nax);

void lazup(int l, int u, int i){
    if(lazy[i] == 0) return;
    seg[i] += lazy[i];
    if(l!=u) {
        lazy[lchild(i)] += lazy[i];
        lazy[rchild(i)] += lazy[i];
    }
    lazy[i] = 0;
}
int update(int l, int u, int i, int LL, int uu, int x) {
    lazup(l, u, i);
    if (l >= LL && u <= uu) {
        lazy[i] += x;
        lazup(l, u, i);
        return seg[i];
    }
    if (l > uu || u < LL) return seg[i];
    return seg[i] = max(update(l, mid(l, u), lchild(i), LL, uu, x) ,
                           update(mid(l, u) + 1, u, rchild(i), LL, uu, x));
}
int query(int l, int u, int i, int LL, int uu){
    lazup(l, u, i);
    if(l>=LL && u<=uu){
        return seg[i];
    }
    if(l>uu || u<LL) return -1e18;
    return max(query(l, mid(l, u), lchild(i), LL, uu) , query(mid(l, u)+1, u, rchild(i), LL, uu));
}
// query(1, n, 0, a, b)  a--start |  b--end | 1based
// update(1, n, 0, a, b, x) a--start | b--end |  add x | 1based

#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,g=3,invg=(cys+1)/3;
int n;
ll ni[200015],fac[200015],inv[200015],tw[200005];

int mod(int x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

vi operator+(vi a,vi b){
	vi ret(max((int)a.size(),(int)b.size()));
	for(int i=0;i<(int)ret.size();i++) ret[i]=mod((i<(int)a.size()?a[i]:0)+(i<(int)b.size()?b[i]:0));
	return ret;
}

vi operator-(vi a,vi b){
	vi ret(max((int)a.size(),(int)b.size()));
	for(int i=0;i<(int)ret.size();i++) ret[i]=mod((i<(int)a.size()?a[i]:0)+cys-(i<(int)b.size()?b[i]:0));
	return ret;
}

vi operator*(vi a,ll b){
	for(int i=0;i<(int)a.size();i++) a[i]=1ll*a[i]*b%cys;
	return a;
}

vi operator>>(vi a,int b){
	for(int i=0;i<(int)a.size()-b;i++) a[i]=a[i+b];
	a.resize((int)a.size()-b);
	return a;
}

namespace poly{
	int N,l;
	int A[1100000],B[1100000],r[1100000],pre1[20][600000],pre2[20][600000];
	void pre(){
		for(int i=1,r=0;i<(1<<19);i<<=1,r++){
			int w=1,wn=qpow(g,(cys-1)/(i<<1));
			for(int j=0;j<i;j++,w=1ll*w*wn%cys) pre1[r][j]=w;
		}
		for(int i=1,r=0;i<(1<<19);i<<=1,r++){
			int w=1,wn=qpow(invg,(cys-1)/(i<<1));
			for(int j=0;j<i;j++,w=1ll*w*wn%cys) pre2[r][j]=w;
		}
	}
	void ntt(int *A,int N,int f){
		for(int i=0;i<N;i++) if(i<r[i]) swap(A[i],A[r[i]]);
		for(int i=1,r=0;i<N;i<<=1,r++){
			for(int j=0;j<N;j+=(i<<1)){
				for(int k=j;k<j+i;k++){
					int x=A[k],y=1ll*A[k+i]*(f>0?pre1[r][k-j]:pre2[r][k-j])%cys;
					A[k]=mod(x+y); A[k+i]=mod(x+cys-y);
				}
			}
		}
		if(f<0){
			int invn=qpow(N,cys-2);
			for(int i=0;i<N;i++) A[i]=1ll*A[i]*invn%cys;
		}
	}
	void init(int t){
		N=1,l=0;
		for(;N<t;N<<=1) l++;
		for(int i=0;i<N;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	}
	void getmul(){
		ntt(A,N,1); ntt(B,N,1);
		for(int i=0;i<N;i++) A[i]=1ll*A[i]*B[i]%cys;
		ntt(A,N,-1);
	}
	vi mul(vi a,vi b){
		init((int)a.size()+(int)b.size());
		for(int i=0;i<N;i++) A[i]=i<(int)a.size()?a[i]:0;
		for(int i=0;i<N;i++) B[i]=i<(int)b.size()?b[i]:0;
		getmul();
		vi ret((int)a.size()+(int)b.size()-1);
		for(int i=0;i<(int)ret.size();i++) ret[i]=A[i];
		return ret;
	}
	vi polyinv(vi a,int l){
		if(l==1) return vi(1,qpow(a[0],cys-2));
		a.resize(l);
		vi b=polyinv(a,(l+1)/2);
		init(l<<1);
		for(int i=0;i<N;i++) A[i]=i<l?a[i]:0;
		for(int i=0;i<N;i++) B[i]=i<(l+1)/2?b[i]:0;
		ntt(A,N,1); ntt(B,N,1);
		for(int i=0;i<N;i++) A[i]=1ll*A[i]*B[i]%cys*B[i]%cys;
		ntt(A,N,-1);
		vi t=b*2;
		t.resize(l);
		for(int i=0;i<l;i++) t[i]=mod(t[i]+cys-A[i]);
		return t;
	}
	vi polydiff(vi a){
		for(int i=0;i<(int)a.size()-1;i++) a[i]=1ll*(i+1)*a[i+1]%cys;
		a.resize((int)a.size()-1);
		return a;
	}
	vi polyint(vi a){
		a.resize((int)a.size()+1);
		for(int i=(int)a.size()-1;i>=1;i--) a[i]=1ll*a[i-1]*ni[i]%cys;
		a[0]=0;
		return a;
	}
	vi polyln(vi a,int l){
		return polyint(mul(polydiff(a),polyinv(a,l)));
	}
	vi polyexp(vi a,int l){
		if(l==1) return vi(1,1);
		a.resize(l);
		vi b=polyexp(a,(l+1)/2);
		init(l<<1);
		vi t=mul(b,vi(1,1)-polyln(b,l)+a);
		t.resize(l);
		return t;
	}
	vi polypow(vi a,int l,int k){
		return polyexp(polyln(a,l)*k,l);
	}
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    poly::pre();

	vi a = {0,10,0,120,0,252,0,120,0,10,0};
	vi b = {1,10,45,120,210,252,210,120,45,10,1};

	// (1 + 2x + 3x^2 + 4x^2)*(1 + 2x + 3x^2)
	// 1 + 4x + 6x^2 + 12x^3 + 9x^4
    poly::pre();
	vi c= poly::mul(a,b);
	for(auto x: c){
		cout<<x<<endl;
	}
	cout<<endl;

	return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
const int mo=998244353;
const int FFTN=1<<18;
#define poly vector<int>
namespace FFT{
	int w[FFTN+5],W[FFTN+5],R[FFTN+5];
	int power(int x,int y){
		int s=1;
		for (;y;y/=2,x=1ll*x*x%mo)
			if (y&1) s=1ll*s*x%mo;
		return s;
	}
	void FFTinit(){
		W[0]=1;
		W[1]=power(3,(mo-1)/FFTN);
		For(i,2,FFTN) W[i]=1ll*W[i-1]*W[1]%mo;
	}
	int FFTinit(int n){
		int L=1;
		for (;L<=n;L<<=1);
		For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
		return L;
	}
	int A[FFTN+5],B[FFTN+5];
	ull p[FFTN+5];
	void DFT(int *a,int n){
		For(i,0,n-1) p[R[i]]=a[i];
		for (int d=1;d<n;d<<=1){
			int len=FFTN/(d<<1);
			for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
			for (int i=0;i<n;i+=(d<<1))
				for (int j=0;j<d;j++){
					int y=p[i+j+d]*w[j]%mo;
					p[i+j+d]=p[i+j]+mo-y;
					p[i+j]+=y;
				}
			if (d==1<<15)
				For(i,0,n-1) p[i]%=mo;
		}
		For(i,0,n-1) a[i]=p[i]%mo;
	}
	void IDFT(int *a,int n){
		For(i,0,n-1) p[R[i]]=a[i];
		for (int d=1;d<n;d<<=1){
			int len=FFTN/(d<<1);
			for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
			for (int i=0;i<n;i+=(d<<1))
				for (int j=0;j<d;j++){
					int y=p[i+j+d]*w[j]%mo;
					p[i+j+d]=p[i+j]+mo-y;
					p[i+j]+=y;
				}
			if (d==1<<15)
				For(i,0,n-1) p[i]%=mo;
		}
		int val=power(n,mo-2);
		For(i,0,n-1) a[i]=p[i]*val%mo;
	}
	poly Mul(const poly &a,const poly &b){
		int sza=a.size()-1,szb=b.size()-1;
		poly ans(sza+szb+1);
		if (sza<=30||szb<=30){
			For(i,0,sza) For(j,0,szb)
				ans[i+j]=(ans[i+j]+1ll*a[i]*b[j])%mo;
			return ans;
		}
		int L=FFTinit(sza+szb);
		For(i,0,L-1) A[i]=(i<=sza?a[i]:0);
		For(i,0,L-1) B[i]=(i<=szb?b[i]:0);
		DFT(A,L); DFT(B,L);
		For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
		IDFT(A,L);
		For(i,0,sza+szb) ans[i]=A[i];
		return ans;
	}
}
using FFT::Mul;
using FFT::power;

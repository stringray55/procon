#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int MAT=8;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

ll mo=1000000007;

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	Mat A;
	FOR(i,8) {
		ll tp[1<<8]={};
		tp[i]=1;
		for(int mask=0;mask<256;mask++) {
			if((mask&31)==31) continue;
			FOR(x,8) if((mask&(1<<x))==0) {
				if(x==3 && ((mask&3)!=3)) continue;
				if(x==4 && ((mask&6)!=6)) continue;
				if(x==5 && ((mask&8)!=8)) continue;
				if(x==6 && ((mask&24)!=24)) continue;
				if(x==7 && ((mask&16)!=16)) continue;
				tp[mask^(1<<x)]+=tp[mask];
			}
		}
		FOR(x,8) A.v[i][x]=tp[(x<<5)|31];
	}
	
	
	cin>>N;
	
	A=powmat(N/2,A);
	if(N%2==0) {
		cout<<A.v[0][0]<<endl;
	}
	else {
		ll ret=0;
		ret+=A.v[0][0]*6;
		ret+=A.v[0][1]*2;
		ret+=A.v[0][2]*2;
		ret+=A.v[0][3]*1;
		ret+=A.v[0][4]*2;
		ret+=A.v[0][5]*1;
		ret+=A.v[0][6]*1;
		cout<<ret%mo<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
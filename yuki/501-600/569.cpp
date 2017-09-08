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

ll N;
ll mo=1000000007;

const int MAT=5*5*5;
struct Mat { ll v[MAT][MAT]; };
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

int ID(int a2,int a1,int a0) { return a2*5*5+a1*5+a0;}

Mat pat;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	FOR(y,MAT) FOR(x,MAT) pat.v[y][x]=0;
	
	// 1 to 1
	FOR(x,4) FOR(y,4) pat.v[ID(x,4,4)][ID(y,4,4)]=1;
	// 3 to 1
	pat.v[ID(0,1,2)][ID(2,4,4)]=1;
	pat.v[ID(0,1,2)][ID(3,4,4)]=1;
	pat.v[ID(0,1,3)][ID(2,4,4)]=1;
	pat.v[ID(0,1,3)][ID(3,4,4)]=1;
	pat.v[ID(0,2,3)][ID(3,4,4)]=1;
	pat.v[ID(1,2,3)][ID(3,4,4)]=1;
	pat.v[ID(2,1,0)][ID(0,4,4)]=1;
	pat.v[ID(3,1,0)][ID(0,4,4)]=1;
	pat.v[ID(3,2,0)][ID(0,4,4)]=1;
	pat.v[ID(3,2,1)][ID(0,4,4)]=1;
	pat.v[ID(3,2,1)][ID(1,4,4)]=1;
	pat.v[ID(3,2,0)][ID(1,4,4)]=1;
	// 1 to 3
	pat.v[ID(0,4,4)][ID(0,1,2)]=1;
	pat.v[ID(0,4,4)][ID(0,1,3)]=1;
	pat.v[ID(0,4,4)][ID(0,2,3)]=1;
	pat.v[ID(0,4,4)][ID(1,2,3)]=1;
	pat.v[ID(1,4,4)][ID(0,2,3)]=1;
	pat.v[ID(1,4,4)][ID(1,2,3)]=1;
	pat.v[ID(2,4,4)][ID(3,1,0)]=1;
	pat.v[ID(2,4,4)][ID(2,1,0)]=1;
	pat.v[ID(3,4,4)][ID(3,1,0)]=1;
	pat.v[ID(3,4,4)][ID(2,1,0)]=1;
	pat.v[ID(3,4,4)][ID(3,2,0)]=1;
	pat.v[ID(3,4,4)][ID(3,2,1)]=1;
	// 3 to 3
	pat.v[ID(0,1,2)][ID(0,1,2)]=1;
	pat.v[ID(0,1,3)][ID(0,1,3)]=1;
	pat.v[ID(0,2,3)][ID(0,2,3)]=1;
	pat.v[ID(1,2,3)][ID(1,2,3)]=1;
	
	pat.v[ID(0,1,2)][ID(0,1,3)]=1;
	pat.v[ID(0,1,3)][ID(0,1,2)]=1;
	pat.v[ID(0,1,3)][ID(0,2,3)]=1;
	pat.v[ID(0,2,3)][ID(0,1,3)]=1;
	pat.v[ID(0,2,3)][ID(1,2,3)]=1;
	pat.v[ID(1,2,3)][ID(0,2,3)]=1;
	
	pat.v[ID(2,1,0)][ID(2,1,0)]=1;
	pat.v[ID(3,1,0)][ID(3,1,0)]=1;
	pat.v[ID(3,2,0)][ID(3,2,0)]=1;
	pat.v[ID(3,2,1)][ID(3,2,1)]=1;
	
	pat.v[ID(2,1,0)][ID(3,1,0)]=1;
	pat.v[ID(3,1,0)][ID(2,1,0)]=1;
	pat.v[ID(3,2,0)][ID(3,1,0)]=1;
	pat.v[ID(3,1,0)][ID(3,2,0)]=1;
	pat.v[ID(3,2,0)][ID(3,2,1)]=1;
	pat.v[ID(3,2,1)][ID(3,2,0)]=1;
	
	cin>>N;
	cout<<powmat(N+1,pat).v[ID(3,4,4)][ID(0,4,4)]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

ll N,P;
ll A[101010],B[101010];
ll SA;

int ok(long double M) {
	long double TP=P*M;
	int i;
	FOR(i,N) if(A[i]*M>B[i]) TP-=A[i]*M-B[i];
	return TP>=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		SA+=A[i];
	}
	if(P>=SA) return _P("-1\n");
	
	long double L=0,R=1e10;
	FOR(i,200) {
		long double M=(L+R)/2;
		if(ok(M)) L=M;
		else R=M;
	}
	
	_P("%.12lf\n",(double)L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

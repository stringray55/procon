#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
ll S[1<<21],K[101000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(x) S[x]++;
	}
	
	for(i=1<<20;i>=0;i--) S[i]+=S[i+1];
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		
		int ret=(1<<20)-1;
		for(j=19;j>=0;j--) if(S[ret-(1<<j)]<=x) ret-=1<<j;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

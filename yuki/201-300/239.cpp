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

int N;
string A[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	r=-1;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	FOR(x,N) {
		int ok=1;
		FOR(y,N) if(x!=y && A[y][x]!="nyanpass") ok=0;
		if(ok) {
			if(r==-1) r=x+1;
			else return _P("-1\n");
		}
		
	}
	return _P("%d\n",r);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

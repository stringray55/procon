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
int A[101];
int sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	FOR(i,N) cin>>A[i], sum+=A[i];
	if(sum%N) return _P("-1\n");
	
	int tot=0,nu=0,ret=0;
	FOR(i,N) {
		nu++;
		tot+=A[i];
		if(tot!=nu*sum/N) ret++;
	}
	cout<<ret<<endl;



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

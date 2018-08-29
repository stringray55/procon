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

int N,K;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int mi=1<<30;
	int fi=N;
	
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) {
		if(i+K<=N) {
			x=A[i];
			y=A[i+K-1];
			
			if(y<=0) mi=min(mi,-x);
			else if(x>=0) mi=min(mi,y);
			else mi=min({mi,2*y-x,y-2*x});
		}
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

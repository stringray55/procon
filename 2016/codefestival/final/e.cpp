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

ll N,A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	
	ll mi=N;
	// once;
	ll X;
	for(X=1;X*(X-1)<=N;X++) mi=min(mi,X+A+(N+(X-1))/X);
	// morethan 1
	for(X=2;X*(X-1)*(X-2)<=N;X++) {
		FOR(x,40) {
			ll pace=1;
			ll tot=0;
			ll t=X;
			FOR(y,40) {
				if(y<x) {
					pace=pace*X;
					tot+=X+A;
				}
				else {
					pace=pace*(X-1);
					tot+=(X-1)+A;
				}
				mi=min(mi,tot+(N+(pace-1))/pace);
				if(pace>N) break;
			}
		}
		
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

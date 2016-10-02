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


ll N,K;
ll mo=924844033;
ll from[2020][2];
ll to[2020][2];
ll fact[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	from[0][0]=1;
	for(i=0;i<min(N,2*K);i++) {
		
		FOR(x,N) if(i>=K) swap(from[x][0],from[x][1]);
		
		for(x=i;x<N;x+=2*K) {
			ZERO(to);
			// prev
			for(y=0;y<N;y++) {
				// prev
				(to[y+1][1] += from[y][1])%=mo;
				// none
				(to[y][1] += from[y][0]+from[y][1])%=mo;
				// next
				if(x+K<N) (to[y+1][0] += from[y][0]+from[y][1])%=mo;
			}
			
			swap(from,to);
		}
		FOR(x,N+1) (from[x][0] += from[x][1])%=mo, from[x][1]=0;
	}
	fact[0]=1;
	FOR(i,N+1) fact[i+1]=fact[i]*(i+1)%mo;
	ll ret=0;
	FOR(i,N+1) ret += from[i][0]*fact[N-i]%mo*((i%2)?-1:1);
	
	cout<<(ret%mo+mo)%mo<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

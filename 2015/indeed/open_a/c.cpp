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

int N,M;
int dp[105][105][105];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	while(N--) cin>>x>>y>>z>>r, dp[x][y][z]=max(dp[x][y][z],r);
	FOR(x,101) FOR(y,101) FOR(z,101) {
		dp[x+1][y][z]=max(dp[x+1][y][z],dp[x][y][z]);
		dp[x][y+1][z]=max(dp[x][y+1][z],dp[x][y][z]);
		dp[x][y][z+1]=max(dp[x][y][z+1],dp[x][y][z]);
	}
	while(M--) cin>>x>>y>>z, cout<<dp[x][y][z]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

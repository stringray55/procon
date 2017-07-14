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

int N,M,S;
ll dp[50][3030];
ll mo=100000;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	N*=N;
	dp[0][0]=1;
	for(i=1;i<=M;i++) {
		for(j=N-1;j>=0;j--) {
			for(x=0;x<=S-i;x++) {
				(dp[j+1][x+i] += dp[j][x])%=mo;
			}
		}
	}
	cout<<dp[N][S]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

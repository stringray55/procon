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

ll dp[101010][3];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll ret=0;
	cin>>S;
	FOR(i,S.size()) {
		dp[i+1][0]=dp[i][0];
		dp[i+1][1]=dp[i][1];
		dp[i+1][2]=dp[i][2];
		
		if(S[i]=='c') dp[i+1][0]++;
		if(S[i]=='w') {
			dp[i+1][2]+=dp[i][1];
			dp[i+1][1]+=dp[i][0];
		}
	}
	cout<<dp[S.size()][2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

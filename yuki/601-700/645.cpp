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

ll N,L,R;
ll mo=1000000007;
ll fact[101010];
ll dp[70];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=100100;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>N>>L>>R;
	dp[1]=1;
	for(i=2;i<=N-1;i++) {
		for(j=65;j>=1;j--) {
			(dp[j+1]+=dp[j])%=mo;
			(dp[j]*=i-1)%=mo;
		}
	}
	ll ret=0;
	for(i=1;i<=61;i++) if(L<=(1LL<<i) && (1LL<<i)<=R) ret+=dp[i];
	if(L==0) ret+=mo+fact[N]-fact[N-1];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

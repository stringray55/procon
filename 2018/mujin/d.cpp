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

int N,M;
int memo[1010][1010];
int vis[1010][1010];

int rev[1010];

int hoge(int A,int B) {
	if(A>B) swap(A,B);
	if(A==0) return 1;
	if(vis[A][B]) return vis[A][B];
	
	vis[A][B]=2;
	int C=rev[A],D=B;
	if(C>D) swap(C,D);
	D-=C;
	
	return vis[A][B]=hoge(C,D);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=999;i++) {
		x=i;
		while(x) {
			rev[i]=rev[i]*10+x%10;
			x/=10;
		}
	}
	
	
	int ret=0;
	cin>>N>>M;
	for(i=1;i<=N;i++) for(j=1;j<=M;j++) ret+=hoge(i,j)==2;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

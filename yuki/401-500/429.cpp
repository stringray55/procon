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

int N,K,X;
int S[101010];
int A[101010],B[101010];
int C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X;
	FOR(i,N) S[i+1]=i+1;
	
	for(i=1;i<=K;i++) {
		cin>>A[i]>>B[i];
		swap(S[A[i]],S[B[i]]);
	}
	cin>>s>>s;
	
	for(i=X+1;i<=K;i++) cin>>A[i]>>B[i];
	FOR(i,N) cin>>C[i+1];
	
	for(i=K;i>X;i--) swap(C[A[i]],C[B[i]]);
	
	
	vector<int> V;
	FOR(i,N) if(S[i+1]!=C[i+1]) V.push_back(i+1);
	_P("%d %d\n",V[0],V[1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

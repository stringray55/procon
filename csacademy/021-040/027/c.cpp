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

int H,W;

int L[101010][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	L[1][0]+=H;
	L[W+1][0]-=H;
	FOR(y,H) {
		cin>>l>>r>>j;
		L[l][j]++;
		L[r+1][j]--;
		L[l][0]--;
		L[r+1][0]++;
	}
	
	int ret=0;
	for(i=1;i<=W;i++) {
		int tot=0;
		for(k=0;k<=10;k++) {
			L[i][k]+=L[i-1][k];
			if(L[i][k]) tot++;
		}
		ret=max(ret,tot);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

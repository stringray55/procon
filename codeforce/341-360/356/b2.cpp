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

int N,A;
int T[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	A--;
	FOR(i,N) cin>>T[i];
	int num=T[A];
	for(i=1;i<=100;i++) {
		x=A-i;
		y=A+i;
		
		if(x<0) num+=(y>=N)?0:T[y];
		else num+=(y>=N)?T[x]:(T[x]+T[y]==2)*2;
	}
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
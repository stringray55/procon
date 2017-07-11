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

int R,C;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>C;
	FOR(y,R) {
		FOR(x,C) {
			cin>>i;
			A[x] |= i<<y;
		}
	}
	
	int ma=0;
	for(int mask=0;mask<1<<R;mask++) {
		int sum=0;
		FOR(x,C) {
			int hoge=__builtin_popcount(A[x]^mask);
			sum += max(hoge,R-hoge);
		}
		ma=max(ma,sum);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

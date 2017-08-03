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

int N;
int A[2020];
ll from[2020];
ll to[2020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) cin>>A[i];
	
	from[0]=1;
	for(i=2;i<=N;i++) {
		ZERO(to);
		ll tot=0;
		if(A[i-2]==0) {
			for(j=i-1;j>=0;j--) {
				tot+=from[j];
				to[j]=tot%mo;
			}
		}
		else {
			FOR(j,i) {
				to[j]=tot%mo;
				tot+=from[j];
			}
		}
		swap(from,to);
	}
	
	cout<<accumulate(from,from+N+1,0LL)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

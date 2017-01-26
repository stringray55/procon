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

int X[101010];
int R[101010];

int cnt[101010];
int id=-1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i];
		R[X[i]]=i;
	}
	
	id=1;
	cnt[1]=1;
	for(i=2;i<=N;i++) {
		if(R[i]>R[i-1]) {
			cnt[i]=cnt[i-1]+1;
			if(cnt[i]>cnt[id]) id=i;
		}
		else {
			cnt[i]=1;
		}
	}
	
	x=id-cnt[id]+1;
	cout<<(x-1)+(N-id)<<endl;
	for(i=x-1;i>=1;i--) cout<<i<<" "<<0<<endl;
	for(i=id+1;i<=N;i++) cout<<i<<" "<<1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

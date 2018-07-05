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
int X[101010],Y[101010];
ll A;
vector<int> V[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	int ma=0;
	FOR(i,2) {
		FOR(x,1010000) V[x].clear();
		FOR(x,N) {
			if(i) V[X[x]].push_back(Y[x]);
			else V[Y[x]].push_back(X[x]);
		}
		
		multiset<int> M;
		for(int x=1;x<=100000;x++) {
			FORR(e,V[x]) M.insert(-e);
			
			while(M.size() && 1LL*(-*M.begin())*x>A) M.erase(M.begin());
			ma=max(ma,(int)M.size());
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

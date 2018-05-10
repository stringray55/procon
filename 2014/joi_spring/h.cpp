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
string S;
map<pair<int,int>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int JI=0,JO=0;
	int ma=0;
	cin>>N>>S;
	M[{0,0}]=-1;
	FOR(i,N) {
		if(S[i]=='J') JI++,JO++;
		if(S[i]=='O') JO--;
		if(S[i]=='I') JI--;
		if(M.count({JI,JO})) ma=max(ma,i-M[{JI,JO}]);
		else M[{JI,JO}]=i;
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
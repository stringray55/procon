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

int N,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	vector<pair<char,int>> V;
	FORR(c,S) {
		if(V.size() && V.back().first==c) {
			V.back().second++;
		}
		else {
			V.push_back({c,1});
		}
		if(V.size() && V.back().second==K) V.pop_back();
	}
	FORR(r,V) {
		FOR(i,r.second) _P("%c",r.first);
	}
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

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

int K;
vector<int> V;
vector<int> ret;

void hoge(int L,int R) {
	if(L>=R) return;
	ret.push_back(V[(L+R)/2]);
	hoge(L,(L+R)/2);
	hoge((L+R)/2+1,R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	for(i=1;i<=(1<<K)-1;i++) V.push_back(i);
	swap(V[V.back()-2],V[V.back()-1]);
	
	hoge(0,V.size());
	
	
	
	FOR(i,ret.size()) _P("%d ",ret[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
int X,Y;
vector<int> E[202020],E2[202020];

int P[21][200005],D[200005],D2[200005];

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}
int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N-1) {
		cin>>x>>y;
		E2[x].push_back(y);
		E2[y].push_back(x);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	P[0][Y]=Y;
	dfs(Y);
	FOR(i,19) FOR(x,N) P[i+1][x+1]=P[i][P[i][x+1]];
	FOR(i,N) D2[i+1]=10101010;
	
	int ret=0;
	queue<int> Q;
	D2[X]=0;
	Q.push(X);
	while(Q.size()) {
		x = Q.front();
		Q.pop();
		ret=max(ret,D[x]);
		if(D2[x]>=D[x]) continue;
		FORR(e,E2[x]) {
			if(dist(x,e)>=3) return _P("-1\n");
			if(D2[e]>D2[x]+1) D2[e]=D2[x]+1, Q.push(e);
		}
	}
	
	cout<<ret*2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

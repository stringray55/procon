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
vector<int> E[303030];
vector<pair<int,int>> MD;
int Q,K;

int P[21][300005],D[300005];
int ID[303030],id;
int num[303030];
int ret[303030];


void dfs(int cur,int pre,int d) {
	D[cur]=d;
	P[0][cur]=pre;
	ID[cur]=++id;
	
	int i,p=-1;
	FOR(i,E[cur].size()) {
		if(E[cur][i]==pre) p=i;
		else dfs(E[cur][i],cur,d+1);
	}
	if(p>=0) E[cur].erase(E[cur].begin()+p);
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs(1,0,1);
	FOR(i,19) FOR(x,N+1) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	while(Q--) {
		cin>>K;
		
		vector<pair<int,int>> V;
		V.push_back({0,0});
		FOR(i,K) {
			cin>>x;
			num[x]=1;
			V.push_back({ID[x],x});
		}
		sort(ALL(V));
		FOR(i,K) {
			x = lca(V[i].second,V[i+1].second);
			V.push_back({ID[x],x});
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		
		ret[0]=N;
		
		vector<int> P;
		FORR(r,V) {
			while(P.size()>1) {
				y = P[P.size()-1];
				if(lca(y,r.second)==y) break;
				x = P[P.size()-2];
				num[x]+=num[y];
				ret[0]-=D[y]-D[x];
				ret[num[y]]+=D[y]-D[x];
				num[y]=0;
				P.pop_back();
			}
			P.push_back(r.second);
		}
		while(P.size()>1) {
			x = P[P.size()-2];
			y = P[P.size()-1];
			num[x]+=num[y];
			ret[0]-=D[y]-D[x];
			ret[num[y]]+=D[y]-D[x];
			num[y]=0;
			P.pop_back();
		}
		
		
		FOR(i,K+1) _P("%d%c",ret[i],(i==K)?'\n':' '), ret[i]=0;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

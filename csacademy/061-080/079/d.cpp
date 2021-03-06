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

int N,K,Q;
int R[101010];
vector<int> V[101010];
int rev[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(rev);
	
	cin>>N>>K>>Q;
	FOR(i,K) {
		cin>>x;
		cin>>R[i];
		rev[R[i]]=i;
		
		x--;
		while(x--) {
			cin>>y;
			V[i].push_back(y);
		}
		sort(ALL(V[i]));
	}
	
	FOR(i,Q) {
		cin>>x;
		vector<int> A,B;
		FOR(j,x) {
			cin>>y;
			if(rev[y]>=0) A.push_back(rev[y]);
			else B.push_back(y);
		}
		sort(ALL(B));
		
		int ret=0;
		FORR(r,A) {
			if(V[r].size()<=B.size()) {
				x=0;
				FORR(b,B) {
					if(x==V[r].size()) break;
					if(V[r][x]==b) x++;
				}
				if(x==V[r].size()) ret++;
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

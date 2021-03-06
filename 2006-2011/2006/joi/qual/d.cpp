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

int N,M;
int p3[17];
int state[15000000];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p3[0]=1;
	FOR(i,16) p3[i+1]=p3[i]*3;
	FOR(i,15000000) state[i]=1<<30;
	
	int cs=0;
	cin>>N>>M;
	FOR(i,3) {
		cin>>x;
		while(x--) {
			cin>>y;
			cs += p3[y-1]*i;
		}
	}
	
	queue<int> Q;
	state[cs]=0;
	Q.push(cs);
	
	while(Q.size()) {
		cs=Q.front();
		Q.pop();
		
		
		int ma[3]={-1,-1,-1};
		FOR(i,N) ma[cs/p3[i]%3]=i;
		
		if(ma[0]<ma[1]) {
			x = cs - p3[ma[1]];
			if(state[x]>state[cs]+1) {
				state[x]=state[cs]+1;
				Q.push(x);
			}
		}
		if(ma[1]<ma[2]) {
			x = cs - p3[ma[2]];
			if(state[x]>state[cs]+1) {
				state[x]=state[cs]+1;
				Q.push(x);
			}
		}
		if(ma[0]>ma[1]) {
			x = cs + p3[ma[0]];
			if(state[x]>state[cs]+1) {
				state[x]=state[cs]+1;
				Q.push(x);
			}
		}
		if(ma[1]>ma[2]) {
			x = cs + p3[ma[1]];
			if(state[x]>state[cs]+1) {
				state[x]=state[cs]+1;
				Q.push(x);
			}
		}
		
	}
	
	
	int ret=min(state[0],state[p3[N]-1]);
	if(ret>M) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

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

int Q;
int A[1010100];
ll V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A[4]=1;
	y=1010100;
	for(i=5;i<=1000000;i++) {
		A[i]=(A[i-1]+A[i-2]+A[i-3]+A[i-4])%17;
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>V;
		if(V>50000) {
			V=50000+(V-50000)%4912;
		}
		cout<<A[V]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}


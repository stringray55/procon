#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	if(A.size()>B.size()) {
		cout<<A<<endl;
		return;
	}
	if(B.size()>A.size()) {
		cout<<B<<endl;
		return;
	}
	FOR(i,A.size()) {
		if(A[i]==B[i]) continue;
		if(A[i]=='7' && B[i]=='4') cout<<B<<endl;
		else if(B[i]=='7' && A[i]=='4') cout<<A<<endl;
		else if(A[i]>B[i]) cout<<A<<endl;
		else cout<<B<<endl;
		break;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

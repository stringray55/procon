#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int X,Y,L;
ll tot;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>L;
	if(Y>0) {
		tot+=(Y+(L-1))/L;
		Y=0;
	}
	if(Y<0) {
		tot+=2+(-Y+(L-1))/L+(abs(X)+(L-1))/L;
	}
	else if(X) {
		tot+=1+(abs(X)+(L-1))/L;
	}
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

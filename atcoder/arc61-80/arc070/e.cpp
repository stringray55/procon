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
int L[101010],R[101010];

multiset<ll> LS,RS;
ll ofl,ofr;
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i]>>R[i];
	
	LS.insert(-1LL<<60);
	RS.insert(1LL<<60);
	
	FOR(i,N) {
		if(i) {
			ofl -= R[i]-L[i];
			ofr += R[i-1]-L[i-1];
		}
	
		if(L[i]<*LS.rbegin()+ofl) ret+=*LS.rbegin()+ofl-L[i];
		else if(*RS.begin()+ofr<L[i]) ret+=L[i]-(*RS.begin()+ofr);
		
		if(L[i]<*LS.rbegin()+ofl) {
			RS.insert(*LS.rbegin()+ofl-ofr);
			LS.insert(L[i]-ofl);
			LS.insert(L[i]-ofl);
			LS.erase(LS.find(*LS.rbegin()));
			
		}
		else if(*RS.begin()+ofr<L[i]) {
			LS.insert(*RS.begin()+ofr-ofl);
			RS.insert(L[i]-ofr);
			RS.insert(L[i]-ofr);
			RS.erase(RS.begin());
		}
		else {
			LS.insert(L[i]-ofl);
			RS.insert(L[i]-ofr);
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

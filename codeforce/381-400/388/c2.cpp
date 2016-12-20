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
string S;
int D,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	deque<char> Q;
	FORR(c,S) {
		if(c=='D') D++;
		else R++;
		Q.push_back(c);
	}
	while(D && R) {
		deque<char> Q2;
		int DC=0,RC=0;
		FORR(c,Q) {
			if(c=='D') {
				if(DC) {
					DC--;
					D--;
				}
				else {
					RC++;
					Q2.push_back(c);
				}
			}
			else {
				if(RC) {
					RC--;
					R--;
				}
				else {
					DC++;
					Q2.push_back(c);
				}
			}
		}
		Q.clear();
		FORR(c,Q2) {
			if(c=='D') {
				if(DC) {
					D--;
					DC--;
				}
				else {
					Q.push_back(c);
				}
			}
			else {
				if(RC) {
					R--;
					RC--;
				}
				else {
					Q.push_back(c);
				}
			}
		}
		
	}
	
	if(D) cout<<"D"<<endl;
	else cout<<"R"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

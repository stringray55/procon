#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class MagicNaming {
	public:
	string st[52][52];
	int dp[52][52];
	int maxReindeers(string magicName) {
		magicName="@"+magicName;
		int N=magicName.size();
		int x,y,l,z;
		FOR(x,N) for(y=1;x+y<=N;y++) st[x][y]=magicName.substr(x,y);
		
		ZERO(dp);
		dp[0][1]=1;
		for(x=0;x<N;x++) for(y=1;x+y<N;y++) {
			if(dp[x][y]==0) continue;
			z=x+y;
			for(l=1;z+l<=N;l++) {
				if(st[x][y]+st[z][l]<=st[z][l]+st[x][y]) dp[z][l]=max(dp[z][l],dp[x][y]+1);
			}
		}
		
		int ret=0;
		FOR(x,N) ret=max(ret,dp[x][N-x]);
		return ret-1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 2; verify_case(0, Arg1, maxReindeers(Arg0)); }
	void test_case_1() { string Arg0 = "babbaba"; int Arg1 = 2; verify_case(1, Arg1, maxReindeers(Arg0)); }
	void test_case_2() { string Arg0 = "philosophersstone"; int Arg1 = 5; verify_case(2, Arg1, maxReindeers(Arg0)); }
	void test_case_3() { string Arg0 = "knuthmorrispratt"; int Arg1 = 7; verify_case(3, Arg1, maxReindeers(Arg0)); }
	void test_case_4() { string Arg0 = "acrushpetrtourist"; int Arg1 = 7; verify_case(4, Arg1, maxReindeers(Arg0)); }
	void test_case_5() { string Arg0 = "zzzzz"; int Arg1 = 5; verify_case(5, Arg1, maxReindeers(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicNaming ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}


#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int dp[51][101];

class ExactTree {
	public:
	int getTree(int n, int m, int r) {
		MINUS(dp);
		dp[1][0]=0;
		int i,j,x,y;
		for(i=2;i<=n;i++) {
			for(j=1;j<i;j++) {
				FOR(x,m) FOR(y,m) if(dp[j][x]>=0 && dp[i-j][y]>=0) {
					int z=dp[j][x]+dp[i-j][y]+j*(n-j);
					if(dp[i][z%m]==-1) dp[i][z%m]=z;
					dp[i][z%m]=min(dp[i][z%m],z);
				}
			}
		}
		return dp[n][r];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 100; int Arg2 = 9; int Arg3 = 9; verify_case(0, Arg3, getTree(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 100; int Arg2 = 10; int Arg3 = 10; verify_case(1, Arg3, getTree(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 100; int Arg2 = 0; int Arg3 = -1; verify_case(2, Arg3, getTree(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 0; int Arg3 = 28; verify_case(3, Arg3, getTree(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 1; int Arg3 = 25; verify_case(4, Arg3, getTree(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 25; int Arg1 = 100; int Arg2 = 0; int Arg3 = 700; verify_case(5, Arg3, getTree(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 97; int Arg2 = 89; int Arg3 = 2708; verify_case(6, Arg3, getTree(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExactTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

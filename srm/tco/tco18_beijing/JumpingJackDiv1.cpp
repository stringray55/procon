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

class JumpingJackDiv1 {
	public:
	int getLocationOfJack(int dist, int k, int x) {
		int ret=0;
		for(int i=1;i<=x;i++) if(i%k) ret+=dist;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; verify_case(0, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; verify_case(1, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(2, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; verify_case(3, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; int Arg3 = 4; verify_case(4, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 10; int Arg3 = 27; verify_case(5, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 10; int Arg3 = 25; verify_case(6, Arg3, getLocationOfJack(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  JumpingJackDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}


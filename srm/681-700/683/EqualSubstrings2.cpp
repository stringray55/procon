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

class EqualSubstrings2 {
	public:
	int get(string s) {
		int ret=0;
		int N=s.size();
		int x,y,l;
		for(l=1;l<=N;l++) {
			for(x=0;x+l<=N;x++) for(y=x+l;y+l<=N;y++) {
				if(s.substr(x,l)==s.substr(y,l)) ret++;
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aa"; int Arg1 = 1; verify_case(0, Arg1, get(Arg0)); }
	void test_case_1() { string Arg0 = "abcd"; int Arg1 = 0; verify_case(1, Arg1, get(Arg0)); }
	void test_case_2() { string Arg0 = "aba"; int Arg1 = 1; verify_case(2, Arg1, get(Arg0)); }
	void test_case_3() { string Arg0 = "abab"; int Arg1 = 3; verify_case(3, Arg1, get(Arg0)); }
	void test_case_4() { string Arg0 = "aaaab"; int Arg1 = 7; verify_case(4, Arg1, get(Arg0)); }
	void test_case_5() { string Arg0 = "onetwothreeonetwothree"; int Arg1 = 86; verify_case(5, Arg1, get(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EqualSubstrings2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

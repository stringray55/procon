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


class ThueMorseGame {
	public:
	
	int win(int n,int m) {
		for(int i=1;i<=m;i++) if(__builtin_popcount(n-i)%2==0 && win(n-i,m)==0) return 1;
		return 0;
	}
	
	string get(int n, int m) {
		int cur=0;
		if(m<=2) return (win(n,m))?"Alice":"Bob";
		
		while(cur+m+1<=n) {
			cur+=m+1;
			while(__builtin_popcount(cur)%2==1) cur++;
		}
		return (cur==n)?"Bob":"Alice";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arg2 = "Alice"; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "Bob"; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 387; int Arg1 = 22; string Arg2 = "Alice"; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 499999999; int Arg1 = 50; string Arg2 = "Alice"; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 499999975; int Arg1 = 49; string Arg2 = "Bob"; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThueMorseGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

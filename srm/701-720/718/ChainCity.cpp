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

int N;
ll X[2020];

class ChainCity {
	public:
	int ok(ll v) {
		int i,num=0;
		ll range=-1;
		FOR(i,N) {
			if(X[i]>range) {
				range=X[i]+v;
				num++;
			}
		}
		return num;
	}
	
	int findMin(vector <int> dist, int k) {
		N=dist.size()+1;
		int i;
		FOR(i,N-1) X[i+1]=X[i]+dist[i];
		
		ll ret=(1LL<<50)-1;
		for(i=49;i>=0;i--) if(ok(ret-(1LL<<i))<=k) ret -= 1LL<<i;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, findMin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, findMin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, findMin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1, 100, 1,1,1, 100, 1, 100, 1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(3, Arg2, findMin(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 8; verify_case(4, Arg2, findMin(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {
1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000
}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 5000000; verify_case(5, Arg2, findMin(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChainCity ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}


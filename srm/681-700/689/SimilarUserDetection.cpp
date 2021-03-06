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

class SimilarUserDetection {
	public:
	string haveSimilar(vector <string> handles) {
		FORR(S,handles) {
			FORR(r,S) {
				if(r=='O') r='0';
				if(r=='I') r='1';
				if(r=='l') r='1';
			}
		}
		int x,y;
		FOR(y,handles.size()) FOR(x,y) if(handles[y]==handles[x]) return "Similar handles found";
		return "Similar handles not found";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"top", "coder", "TOPCODER", "TOPC0DER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles found"; verify_case(0, Arg1, haveSimilar(Arg0)); }
	void test_case_1() { string Arr0[] = {"Topcoder", "topcoder", "t0pcoder", "topcOder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles not found"; verify_case(1, Arg1, haveSimilar(Arg0)); }
	void test_case_2() { string Arr0[] = {"same", "same", "same", "different"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles found"; verify_case(2, Arg1, haveSimilar(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles found"; verify_case(3, Arg1, haveSimilar(Arg0)); }
	void test_case_4() { string Arr0[] = {"i23", "123", "456", "789", "000", "o", "O"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles not found"; verify_case(4, Arg1, haveSimilar(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimilarUserDetection ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

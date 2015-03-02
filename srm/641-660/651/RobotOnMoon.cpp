#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int dist[100][100];

class RobotOnMoon {
	public:
	int H,W;
	int longestSafeCommand(vector <string> B) {
		H=B.size();
		W=B[0].size();
		int sy,sx,i,j,x,y;
		FOR(y,H) FOR(x,W) if(B[y][x]=='S') sy=y,sx=x,B[y][x]='.';
		FOR(y,H) if(B[y][sx]=='#') return -1;
		FOR(x,W) if(B[sy][x]=='#') return -1;
		return H+W-2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, longestSafeCommand(Arg0)); }
	void test_case_1() { string Arr0[] = {"S......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, longestSafeCommand(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, longestSafeCommand(Arg0)); }
	void test_case_3() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, longestSafeCommand(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RobotOnMoon ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

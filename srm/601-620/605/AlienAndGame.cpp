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

class AlienAndGame {
	int same[51][51];
	public:
	int getNumber(vector <string> board) {
		int H=board.size(),W=board[0].size();
		int y,x,w,l=1;
		ZERO(same);
		FOR(y,H) {
			for(x=W-1;x>=0;x--) {
				if(x<W-1 && board[y][x]==board[y][x+1]) same[y][x]=same[y][x+1];
				same[y][x]++;
			}
		}
		FOR(y,H) FOR(x,W) {
			for(w=1;x+w<=W;w++) {
				int ng=0;
				if(y+w>H) break;
				for(int y2=y;y2<y+w;y2++) if(same[y2][x]<w) ng++;
				
				if(ng) break;
				l=max(l,w);
			}
		}
		return l*l;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBB",
 "WBBB",
 "WWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"W",
 "B",
 "W",
 "W",
 "W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlienAndGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}


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

int cost[51][51];

class ShortestPathWithMagic {
	public:
	double getTime(vector <string> S, int k) {
		int i,j,x,y;
		
		int N=S.size();
		FOR(x,N+1) FOR(y,k+1) cost[x][y]=999999;
		cost[0][k]=0;
		priority_queue<pair<int,int> > PQ;
		PQ.push({0,k*100});
		
		while(PQ.size()) {
			auto r=PQ.top();
			PQ.pop();
			int co=-r.first;
			int nk=r.second/100;
			int cur=r.second%100;
			if(cur==1) return co/2.0;
			if(cost[cur][nk]<co) continue;
			
			FOR(i,N) {
				if(cost[i][nk]>cost[cur][nk]+2*(S[i][cur]-'0')) {
					cost[i][nk] = cost[cur][nk]+2*(S[i][cur]-'0');
					PQ.push({-cost[i][nk], nk*100+i});
				}
				if(nk && cost[i][nk-1]>cost[cur][nk]+(S[i][cur]-'0')) {
					cost[i][nk-1] = cost[cur][nk]+(S[i][cur]-'0');
					PQ.push({-cost[i][nk-1], (nk-1)*100+i});
				}
			}
		}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 4.5; verify_case(0, Arg2, getTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 4.0; verify_case(1, Arg2, getTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 4.0; verify_case(2, Arg2, getTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 8.0; verify_case(3, Arg2, getTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"076237",
 "708937",
 "680641",
 "296059",
 "334508",
 "771980"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.5; verify_case(4, Arg2, getTime(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(5, Arg2, getTime(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShortestPathWithMagic ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

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

ll mo=1000000007;
const int CN=401;
ll C[CN][CN];

class GravityPuzzle {
	public:
	int H,W;
	int count(vector <string> B) {
		H=B.size();
		W=B[0].size();
		int i,j;
		FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
		
		int U=1,D=1,L=1,R=1;
		int y,x;
		int sum=0;
		FOR(y,H) FOR(x,W) B[y][x]=(B[y][x]=='#');
		FOR(y,H) FOR(x,W) if(B[y][x]==1) {
			sum++;
			if(y&&B[y-1][x]==0) U=0;
			if(y<H-1&&B[y+1][x]==0) D=0;
			if(x&&B[y][x-1]==0) L=0;
			if(x<W-1&&B[y][x+1]==0) R=0;
		}
		if(L+R+U+D==4) return 1;
		if(L+R+U+D==0) return 1;
		if(L+R==2 || L+R==0) {
			ll ret=1;
			if(U+D==0) return 1;
			FOR(x,W) {
				int cnt=0;
				FOR(y,H) cnt+=B[y][x];
				(ret *= C[H][cnt])%=mo;
			}
			return ret;
		}
		if(U+D==2 || U+D==0) {
			ll ret=1;
			if(L+R==0) return 1;
			FOR(y,H) {
				int cnt=0;
				FOR(x,W) cnt+=B[y][x];
				(ret *= C[W][cnt])%=mo;
			}
			return ret;
		}
		
		FOR(y,H) {
			FOR(x,W) cout<<(B[y][x]?'#':'.');
			cout<<endl;
		}
		
		ll ret[3]={1,1};
		int cnt[2][55]={};
		FOR(x,W) {
			int d=0;
			FOR(y,H) d+=B[y][x];
			cnt[0][d]++;
			(ret[0]*=C[H][d])%=mo;
		}
		FOR(y,H) {
			int d=0;
			FOR(x,W) d+=B[y][x];
			cnt[1][d]++;
			(ret[1]*=C[W][d])%=mo;
		}
		int nw=0,nh=0;
		ll a=1,b=1;
		for(i=0;i<=51;i++) {
			nw+=cnt[0][i];
			(a*=C[nw][cnt[0][i]])%=mo;
			nh+=cnt[1][i];
			(b*=C[nh][cnt[1][i]])%=mo;
		}
		
		
		return ((ret[0]*a+ret[1]*b-a*b)%mo+mo)%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#...",
 "....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {".#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.",
 "##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {".##",
 "..#",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {".##########.",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999937; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GravityPuzzle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}


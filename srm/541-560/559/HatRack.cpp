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
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long u64;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class HatRack {
	public:
	int N;
	int MD,left;
	int ncon[52];
	int mat[52][52];
	
	ll npat[52][52];
	int nhat[52][52];
	int ndep[52][52];
	
	void dfs(int from, int cur) {
		int i,tar,t[2],nt;
		int first=(from==51)?1:0;
		if(ndep[from][cur]!=-1) return;
		
		if(ncon[cur]==1) {
			ndep[from][cur]=0;
			nhat[from][cur]=1;
			npat[from][cur]=1;
			goto out;
		}
		else if(ncon[cur]==2) {
			FOR(i,ncon[cur]) {
				tar = mat[cur][i];
				if(tar!=from) {
					dfs(cur,tar);
					if(ndep[cur][tar]!=0) {
						ndep[from][cur] = -2;
					}
					else {
						ndep[from][cur] = 1;
						npat[from][cur] = 1;
						nhat[from][cur] = 2;
					}
					goto out;
				}
			}
		}
		else if(ncon[cur]==3) {
			nt=0;
			FOR(i,ncon[cur]) {
				tar = mat[cur][i];
				if(tar == from) continue;
				t[nt++]=tar;
				dfs(cur,tar);
			}
			
			nhat[from][cur]=nhat[cur][t[0]]+nhat[cur][t[1]]+1;
			if(ndep[cur][t[0]]==-2 || ndep[cur][t[1]]==-2) {
				ndep[from][cur] = -2;
			}
			else if(ndep[cur][t[0]]==ndep[cur][t[1]]) {
				if(nhat[cur][t[0]] != (1<<(1+ndep[cur][t[0]]))-1 &&
				   nhat[cur][t[1]] != (1<<(1+ndep[cur][t[1]]))-1) {
					ndep[from][cur]=-2;
					goto out;
				}
				ndep[from][cur]=ndep[cur][t[0]]+1;
				if(nhat[cur][t[0]] == (1<<(1+ndep[cur][t[0]]))-1 &&
				   nhat[cur][t[1]] == (1<<(1+ndep[cur][t[1]]))-1) {
					npat[from][cur]=2*npat[cur][t[0]]*npat[cur][t[1]];
				}
				else {
					npat[from][cur]=npat[cur][t[0]]*npat[cur][t[1]];
				}
			}
			else if(ndep[cur][t[0]]==ndep[cur][t[1]]+1) {
				if(nhat[cur][t[1]] != (1<<(1+ndep[cur][t[1]]))-1) {
					ndep[from][cur]=-2;
				}
				else {
					ndep[from][cur]=ndep[cur][t[0]]+1;
					npat[from][cur]=npat[cur][t[0]]*npat[cur][t[1]];
				}
			}
			else if(ndep[cur][t[0]]+1==ndep[cur][t[1]]) {
				if(nhat[cur][t[0]] != (1<<(1+ndep[cur][t[0]]))-1) {
					ndep[from][cur]=-2;
				}
				else {
					ndep[from][cur]=ndep[cur][t[1]]+1;
					npat[from][cur]=npat[cur][t[0]]*npat[cur][t[1]];
				}
			}
			else {
				ndep[from][cur] = -2;
			}
		}
out:
		//_P("%d->%d %d %d %lld\n",from,cur,ndep[from][cur],nhat[from][cur],npat[from][cur]);
		return;
	}
	
	
	long long countWays(vector <int> knob1, vector <int> knob2) {
		int i,j;
		N=knob1.size()+1;
		MD=0;
		while(N>=(1<<(MD+1))) MD++;
		left = N-((1<<(MD-1))-1);
		
		
		ZERO(ncon);
		ZERO(mat);
		FOR(i,knob1.size()) {
			int f = knob1[i]-1;
			int t = knob2[i]-1;
			mat[f][ncon[f]++] = t;
			mat[t][ncon[t]++] = f;
		}
		FOR(i,N) if(ncon[i]==0 || ncon[i]>=4) return 0;
		
		ZERO(npat);
		MINUS(nhat);
		MINUS(ndep);
		long long res=0;
		FOR(i,N) {
			mat[i][ncon[i]++]=51;
			dfs(51,i);
			ncon[i]--;
			if(ndep[51][i]==MD) res += npat[51][i];
		}
		
		return res;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
//	void test_case_3() { int Arr0[] = {6,6,6,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8,6,5,4,7,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,6,6,5,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,2,2,11,11,8,8,3,3,4,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,11,8,12,13,9,10,4,5,7,6,14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  HatRack ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE

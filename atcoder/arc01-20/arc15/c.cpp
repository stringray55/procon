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
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
int GETi() { int i;scanf("%d",&i); return i;}

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
double mat[401][401];
map<string,int> AA;
string SS[401];

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	int N;
	cin>>N;
	FOR(i,N) {
		string s1,s2;
		cin>>s1>>j>>s2;
		if(AA.find(s1)==AA.end()) {
			AA[s1]=AA.size()-1;
			SS[AA[s1]]=s1;
		}
		if(AA.find(s2)==AA.end()) {
			AA[s2]=AA.size()-1;
			SS[AA[s2]]=s2;
		}
		
		mat[AA[s2]][AA[s1]]=j;
		mat[AA[s1]][AA[s2]]=1.0/j;
	}
	N=AA.size();
	
	FOR(j,2) {
		FOR(i,N) FOR(x,N) FOR(y,N) {
			if(mat[x][y]==0 && mat[x][i]>0 && mat[i][y]>0) mat[x][y]=mat[x][i]*mat[i][y];
			if(mat[x][y]==0 && mat[x][i]>0 && mat[y][i]>0) mat[x][y]=mat[x][i]/mat[y][i];
		}
	}
	double la=0;
	string fr,to;
	FOR(x,N) FOR(y,N) {
		if(la<mat[x][y]) {
			la=mat[x][y];
			fr=SS[y];
			to=SS[x];
		}
	}
	_P("1%s=%lld%s\n",fr.c_str(),(ll)(la+0.001),to.c_str());
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}

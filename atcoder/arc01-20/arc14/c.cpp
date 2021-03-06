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
#include <sys/time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
string S;
set<string> SS[2];

void solve() {
	int f,r,i,j,k,l;
	int bad[2];
	
	N=GETi();
	cin>>S;
	
	SS[0].insert("");
	FOR(i,N) {
		SS[1]=SS[0];
		SS[0].clear();
		k = 50;
		ITR(x,SS[1]) k=min(k,(int)x->length());
		
		ITR(x,SS[1]) {
			const string& s=*x;
			l = s.length();
			if(l>k+5) continue;
			char cc[2];
			cc[0]=S[i];
			cc[1]=0;
			
			if(l==0) SS[0].insert(cc);
			else {
				if((*x)[0]==S[i]) SS[0].insert(s.substr(1));
				else if(l<=N/2+3) SS[0].insert(string(cc) + s);
				if(s[l-1]==S[i]) SS[0].insert(s.substr(0,l-1));
				else if(l<=N/2+3) SS[0].insert(s + string(cc));
			}
		}
	}
	
	k = 50;
	ITR(x,SS[0]) k=min(k,(int)x->length());
	_P("%d\n",k);
	
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}

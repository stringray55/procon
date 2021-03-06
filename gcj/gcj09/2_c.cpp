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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif


#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

//-------------------------------------------------------

int N,K;
char line[1000];
int price[100][100];
int matrix[100][100];

int np[100];
int tested[100];

int GetNext(int cur) {
	int i;
	if(cur<0) return 1;
	if(tested[cur]) return 0;
	tested[cur]=1;
	FOR(i,N) {
		if(matrix[cur][i]==0) continue;
		if(GetNext(np[i])) {
			np[i]=cur;
			return 1;
		}
	}
	return 0;
}

void solve(int _loop) {
	int i,j,k,result,x,y,dir;
	GET2(&N,&K);
	ZERO(price);
	ZERO(matrix);
	
	FOR(i,N) {
		matrix[i][i]=0;
		FOR(j,K) {
			GET1(&price[i][j]);
		}
	}
	
	FOR(i,N) {
		FOR(j,N) {
			matrix[i][j]=1;
			for(k=0;k<K;k++) {
				if(price[i][k]>=price[j][k]) {
					matrix[i][j]=0; break;
				}
			}
		}
	}
	
	MINUS(np);
	result=0;
	FOR(i,N) {
		ZERO(tested);
		if(!GetNext(i))
			result++;
	}
	
	_PE("Case #%d: %d\n",_loop,result);
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}




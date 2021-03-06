#include <bits/stdc++.h>
#include <sys/time.h>
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

int N,K;
double R[1010],A[1010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	double pi=atan(1)*4;
	cin>>N>>K;
	FOR(i,N) {
		cin>>R[i]>>A[i];
		A[i] = A[i]*R[i]*2*pi;
		R[i] = R[i]*R[i]*pi;
	}
	
	double ma=0;
	FOR(i,N) {
		vector<double> D;
		FOR(j,N) if(i!=j && R[j]<=R[i]) D.push_back(A[j]);
		sort(ALL(D));
		reverse(ALL(D));
		if(D.size()<K-1) continue;
		D.resize(K-1);
		D.push_back(A[i]);
		ma=max(ma,accumulate(ALL(D),0.0)+R[i]);
	}
	
	_P("Case #%d: %.12lf\n",_loop,ma);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}



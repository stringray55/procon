#include <bits/stdc++.h>
using namespace std;

int main(int argc,char** argv){
	int N, M, C;
	
	cin >> N >> M >> C;
	
	// Nが小さくなるようにswap
	if(N > M) swap(N,M);
	
	if(N==1) {
		// N==1の時、Mが３以上だと条件を満たさない
		if(M==2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		// N,M>1なら、縦横どちらかが偶数なら条件を満たす。
		if (N*M % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}


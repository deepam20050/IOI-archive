// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1464
// AC 
// Too many floating point problems 

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

double ar[N];

int n,k;

bool count(double x) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += (int)(ar[i]/x);
	}
	return cnt >= k;
}

int main() {

	int t;
	scanf("%d",&t);

	while (t--) {

	scanf("%d %d",&n,&k);

	for (int i = 0; i < n; ++i) {
		scanf("%lf",&ar[i]);
	}

	double l = 0, r = 1e5+5;

	for (int i = 1; i < 100; ++i) {
		double m = (l + r) / 2;
		if (count(m))
			l = m;
		else r = m;
	}


	printf("%.2f\n",floor(l*100)/100);
}
	return 0;
}
// http://codeforces.com/problemset/problem/279/B
// AC

#include <bits/stdc++.h>

using namespace std;

int ar[100000];
long sum[100001];
int n;
long total;

int main() {
	scanf("%d %ld",&n,&total);

	for (int i = 0; i < n; ++i) {
		scanf("%d",&ar[i]);
	}
	
	int ans = 0;

	for (int i = n-1; i >= 0; --i) {
		sum[i] = sum[i+1] + ar[i];
	}
	
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while ((j < n) && sum[i] - sum[j+1] <= total) {
			++j;
		}
		ans = max(ans,j-i);
	}

	printf("%d\n",ans);
	return 0;
}

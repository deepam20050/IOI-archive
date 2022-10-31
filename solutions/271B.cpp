// http://codeforces.com/problemset/problem/271/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

bool used[N];
int row[500], col[500];

int main() {
	used[0] = used[1] = 1;
	for (int i = 2; i*i < N; ++i) {
		if (!used[i]) {
			for (int j = i + i; j < N; j += i) 
				used[j] = 1;
		}
	}

	int n,m;
	scanf("%d %d",&n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a;
			scanf("%d",&a);
			int x = a;
			while (used[x]) {
				++x;
			}
			row[i] += (x - a);
			col[j] += (x - a);
		}
	}

	int a = *min_element(row,row+n);
	int b = *min_element(col,col+m);

	printf("%d\n",min(a,b));

	return 0;
}
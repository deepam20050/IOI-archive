// https://dmoj.ca/problem/ccc14s3

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;

int a[N], b[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		stack <int> branch;
		int agla = 1, j = 0;
		for (int i = n - 1; i >= 0; --i) {
			int x = a[i];
			if (x == agla) {
				b[j++] = agla++;
			} else {
				while(!branch.empty() && branch.top() == agla) {
					b[j++] = agla++;
					branch.pop();
				} 
				branch.push(x);
			}
		}
		while (!branch.empty()) {
			b[j++] = branch.top();
			branch.pop();
		}
		if (is_sorted(b, b + n)) {
			puts("Y");
		} else {
			puts("N");
		}
	}
	return 0;
}
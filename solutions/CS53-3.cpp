// https://csacademy.com/contest/round-53/task/histogram-partition/

#include <bits/stdc++.h>

using namespace std;

stack <int> s;

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		int x = 0;
		if (i < n) {
			scanf("%d", &x);
		}
		while (!s.empty() && s.top() > x) {
			s.pop();
			++sum;
		}
		if (s.empty() || s.top() < x) {
			s.push(x);
		}
	}
	printf("%d", sum);
	return 0;
}
// http://codeforces.com/problemset/problem/547/B

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N];
stack <int> s1;
stack <int> s2;
int ans[N];
int l[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	s1.push(0);
	for (int i = 1; i <= n; ++i) {
		while (a[s1.top()] >= a[i]) {
			s1.pop();
		}
		l[i] = s1.top();
		s1.push(i);
	}
	s2.push(n + 1);
	for (int i = n; i >= 1; --i) {
		while (a[s2.top()] >= a[i]) {
			s2.pop();
		}
		ans[s2.top() - l[i] - 1] = max(ans[s2.top() - l[i] - 1], a[i]);
		s2.push(i);
	}
	for (int i = n; i >= 1; --i) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}
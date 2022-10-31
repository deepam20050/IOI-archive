// https://www.codechef.com/problems/TRAVLMIN

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

pair <int, int> p[N];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &p[i].second, &p[i].first);
	}
	sort(p, p + n);
	int prev = -1, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i].second > prev) {
			++cnt;
			prev = p[i].first;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
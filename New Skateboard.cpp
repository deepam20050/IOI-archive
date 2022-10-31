// http://codeforces.com/problemset/problem/628/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

char s[N];

bool check(char a, char b) {
	int aa = a - '0', bb = b - '0';
	return (aa * 10 + bb) % 4  == 0 ? 1 : 0;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	long long ans = ((s[0] - '0') % 4 == 0 ? 1 : 0);
	for (int i = 1; i < n; ++i) {
		if (check(s[i - 1], s[i])) {
			ans += i;
		}
		if ((s[i] - '0') % 4 == 0) {
			++ans;
		}
		//cout << ans << '\n';
	}
	printf("%lld\n",ans);
	return 0;
}
// http://codeforces.com/contest/626/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 210;

bool dp[N][N][N];
char s[N];

void go(int r, int g, int b) {
	if (dp[r][g][b]) return;
	dp[r][g][b] = 1;

	if (r >= 2)
		go(r - 1, g, b);
	if (g >= 2)
		go(r, g - 1, b);
	if (b >= 2)
		go(r, g, b - 1);
	if (r >= 1 && g >= 1)
		go(r - 1, g - 1, b + 1);
	if (r >= 1 && b >= 1)
		go(r - 1, g + 1, b - 1);
	if (g >= 1 && b >= 1)
		go(r + 1, g - 1, b - 1);
}

int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int r = 0, b = 0, g = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') ++r;
		else if (s[i] == 'B') ++b;
		else ++g;
	}
	go(r, g, b);

	if (dp[0][0][1]) putchar('B');
	if (dp[0][1][0]) putchar('G');
	if (dp[1][0][0]) putchar('R');

	return 0;
}
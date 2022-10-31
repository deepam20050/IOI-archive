// http://codeforces.com/problemset/problem/758/B

#include "bits/stdc++.h"

using namespace std;

const int N = 123;

char s[N];
char c[4];
int a[N];

inline int g(char c) {
	if (c == 'R') {
		return 0;
	}
	if (c == 'B') {
		return 1;
	}
	if (c == 'Y') {
		return 2;
	}
	return 3;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] != '!') {
			c[i % 4] = s[i - 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == '!') {
			++a[g(c[i % 4])];
		}
	}
	for (int i = 0; i < 4; ++i) {
		printf("%d ", a[i]);
	}
	return 0;
}
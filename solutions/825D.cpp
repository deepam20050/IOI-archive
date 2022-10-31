// http://codeforces.com/problemset/problem/825/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char s[N], t[N];
int c1[26], c2[26];
stack <int> st;

int q = 0;

bool F(int m) {
	int add = 0;
	for (int i = 0; i < 26; ++i) {
		int diff = c2[i] * m - c1[i];
		if (diff >= 0) {
			add += diff;
		}
	}
	return add <= q;
}

int main() {
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s), m = strlen(t);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			++q;
			st.push(i);
		}  else {
			++c1[s[i] - 'a'];
		}
	}
	for (int i = 0; i < m; ++i) {
		++c2[t[i] - 'a'];
	}
	int ans = 0;
	for (int i = 0; i <= n / m; ++i) {
		if (F(i)) {
			ans = i;
		}
	}
	for (int i = 0; i < 26; ++i) {
		int diff = c2[i] * ans - c1[i];
		while (!st.empty() && diff > 0) {
			s[st.top()] = i + 'a';
			st.pop();
			--diff;
		}
	}
	while (!st.empty()) {
		s[st.top()] = 'a';
		st.pop();
	}
	puts(s);
	return 0;
}
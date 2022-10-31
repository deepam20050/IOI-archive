// https://dmoj.ca/problem/ccc99s5

#include "bits/stdc++.h"

using namespace std;

const int N = 26, M = 10;

bool used[N], there[M];
int assigned[N];

string a, b, c, s;
int sz;

void calc(const string &ss) {
	for (char ch: ss) {
		if (!used[ch - 'A']) {
			used[ch - 'A'] = 1;
			s += ch;
		}
	}
}

bool check() {
	int i = a.size() - 1, j = b.size() - 1, k = c.size() - 1, carry = 0;
	while (min(i, min(j, k)) >= 0) {
		int n1 = assigned[a[i] - 'A'], n2 = assigned[b[j] - 'A'], n3 = assigned[c[k] - 'A'];
		if ((n1 + n2 + carry) % 10 != n3) {
			return 0;
		}
		carry = (n1 + n2 + carry) / 10;
		--i;
		--j;
		--k;
	}
	if (i == -1) {
		while (j >= 0) {
			int n = assigned[b[j] - 'A'];
			if ((n + carry) % 10 != assigned[c[k] - 'A']) {
				return 0;
			}
			carry = (n + carry) / 10;
			--j;
			--k;
		}
	} else {
		while (i >= 0) {
			int n = assigned[a[i] - 'A'];
			if ((n + carry) % 10 != assigned[c[k] - 'A']) {
				return 0;
			}
			carry = (n + carry) / 10;
			--i;
			--k;
		}
	}
	if (c.size() == max(a.size(), b.size()) + 1) {
		if (assigned[c[0] - 'A'] != carry) {
			return 0;
		}
	}
	return 1;
}

bool solve (int idx) {
	if (idx == sz) {
		if (check()) {
			return 1;
		}
		return 0;
	}
	for (int i = (c[0] == s[idx] || a[0] == s[idx] || b[0] == s[idx]) ? 1 : 0; i < 10; ++i) {
		if (!there[i]) {
			there[i] = 1;
			assigned[s[idx] - 'A'] = i;
			if (solve(idx + 1)) {
				return 1;
			}
			there[i] = 0;
			assigned[s[idx] - 'A'] = -1;
		}
	}
	return 0;
}

void print(const string &ss) {
	for (char ch: ss) {
		printf("%d", assigned[ch - 'A']);
	}
	puts("");
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		cin >> a >> b >> c;
		s = "";
		calc(a);
		calc(b);
		calc(c);
		sz = s.size();
		memset(used, 0, sizeof used);
		memset(there, 0, sizeof there);
		memset(assigned, -1, sizeof assigned);
		solve(0);
		print(a);
		print(b);
		print(c);
	}
	return 0;
}
// http://codeforces.com/contest/689/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

char s[N];
int z[4][3] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{-1, 0, -1}
};
vector < pair <int, int> > p;

pair <int, int> f(int x) {
	pair <int, int> p;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (z[i][j] == x) {
				p = {i, j};
				break;
			}
		}	
	}
	return p;
}

bool check(int i, int j) {
	int x = 0;
	while (i >= 0 && j >= 0 && i < 4 && j < 3 && x < p.size()) {
		if (z[i][j] == -1) {
			return 0;
		}
		i += p[x].first;
		j += p[x].second;
		++x;
	}
	return x == p.size() && i >= 0 && j >= 0 && i < 4 && j < 3 && z[i][j] != -1;
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int b = s[0] - '0';
	for (int i = 1; i < n; ++i) {
		auto p1 = f(s[i] - '0');
		auto p2 = f(b);
		p.push_back({p1.first - p2.first, p1.second - p2.second});
		b = s[i] - '0';
	}
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 3 && j == 1 && check(i, j)) {
				++ans;
			} else if (i != 3 && check(i, j)) {
				++ans;
			}
		}
	}
	ans == 1 ? puts("YES") : puts("NO");
	return 0;
}
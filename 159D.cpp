// http://codeforces.com/contest/159/problem/D

#include "bits/stdc++.h"

using namespace std;

const int N = 1 << 11;

int sum[N]; // Number of valid palindromic substrings with starting index index i
bool pal[N][N];

int main() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		int idx1 = i;
		int idx2 = i;
		while (idx1 >= 1 && idx2 <= n && s[idx1] == s[idx2]) { // Consider palindromes from i extending left and right
			++sum[idx1];
			pal[idx1--][idx2++] = 1;
		}
		idx1 = i;
		idx2 = i + 1;
		while (idx1 >= 1 && idx2 <= n && s[idx1] == s[idx2]) { // Consider palindromes that have their first two elements at i and i + 1
			++sum[idx1];
			pal[idx1--][idx2++] = 1;
		}
		// We are not considering palindromes for i and i - 1 because they are already considered in the previous iteration
	}
	long long ans = 0;
	for (int i = n - 1; i >= 1; --i) {
		sum[i] += sum[i + 1];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (pal[i][j]) {
				ans += sum[j + 1];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
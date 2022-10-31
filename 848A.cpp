// http://codeforces.com/contest/848/problem/A

#include "bits/stdc++.h"

using namespace std;

string ans;

int main() {
	int k;
	scanf("%d", &k);
	char ch = 'a';
	if (k == 0) {
		return !printf("a");
	}
	while (k > 0) {
		int n = 1;
		while ((n * (n - 1)) / 2 <= k) {
			++n;
		}
		--n;
		for (int i = 0; i < n; ++i) {
			putchar(ch);
		}
		k -= (n * (n - 1)) / 2;
		++ch;
	}
	return 0;
}
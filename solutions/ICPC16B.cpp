// https://www.codechef.com/problems/ICPC16B

#include "bits/stdc++.h"

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int one = 0, minus1 = 0, zero = 0, others = 0;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			if (x == 0) {
				++zero;
			} else if (x == -1) {
				++minus1;
			} else if (x == 1){
				++one;
			} else {
				++others;
			}
		}
		if (others > 1) {
			puts("no");
		} else if (minus1 && others) {
			puts("no");
		} else if (minus1 > 1 && !one) {
			puts("no");
		} else {
			puts("yes");
		}
	}
	return 0;
}
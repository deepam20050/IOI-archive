// https://arc059.contest.atcoder.jp/tasks/arc059_b

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char str[N];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			printf("%d %d\n", i + 1, i + 2);
			return 0;
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (str[i] == str[i + 2]) {
			printf("%d %d\n", i + 1, i + 3);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}
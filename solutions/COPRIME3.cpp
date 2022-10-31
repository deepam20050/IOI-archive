#include <bits/stdc++.h>

using namespace std;

int main() {
	for (int i = 2; i < M; ++i) {
		if (!prime[i]) {
			for (int j = i + i; j < M; j += i) {
				if (!sp[j]) {
					sp[j] = i;
				}
			}
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		int curr = 1;
		while (arr[i] > 1) {
			int curr_sp = sp[arr[i]];
			curr *= curr_sp;
			while (arr[i] % curr_sp == 0) {
				arr[i] /= curr_sp;
			}
		}
		arr[i] = curr;
	}
	
	return 0;
}
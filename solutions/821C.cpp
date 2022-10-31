// http://codeforces.com/problemset/problem/821/C

#include <bits/stdc++.h>

using namespace std;

stack <int> st;

int main() {
	int n;
	scanf("%d", &n);
	int curr = 1, ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		string op;
		cin >> op;
		if (op == "add") {
			int x;
			scanf("%d", &x);
			st.push(x);
		} else {
			if (!st.empty()) {
				if (st.top() == curr) {
					st.pop();
				} else {
					while (!st.empty()) {
						st.pop();
					}
					++ans;
				}
			}
			++curr;
		}
	}
	printf("%d", ans);
	return 0;
}
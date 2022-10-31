// http://codeforces.com/problemset/problem/730/H
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

vector <string> v(N);
string ans;
int ar[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> ar[i];
	}

	int tmo = v[ar[0]].size();
	for (int i = 1; i < m; ++i) {
		if (v[ar[i]].size() != tmo) {
			puts("No");
			return 0;
		}
	}

	for (int i = 0; i < tmo; ++i) {
		set <char> st;
		
		for (int j = 0; j < m; ++j) {
			st.insert(v[ar[j]][i]);
		}

		if (st.size() > 1) {
			ans += '?';
		} else {
			ans += *(st.begin());
		}
	}

	sort(ar, ar + n);

	for (int i = 1; i <= n; ++i) {
		if (binary_search(ar, ar + n, i) || v[i].size() != ans.size()) continue;
		int diff = 0;
		for (int j = 0; j < tmo; ++j) {
			if (ans[j] == '?') continue;
			if (ans[j] != v[i][j]) ++diff;
		}
		if (diff == 0) {
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	cout << ans;

	return 0;
}
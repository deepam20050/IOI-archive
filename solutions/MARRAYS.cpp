// https://www.codechef.com/problems/MARRAYS
/* When dealing with values like |x| then consider it as two separate cases like
 * +x and -x and also if something like : A * |x| then distribute the multiplication
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const long long oo = 1LL << 60;

vector <long long> a[N];
vector <long long> z[N];

int get(int i, int m) {
	return (i % m + m) % m;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int m;
			scanf("%d", &m);
			a[i].clear();
			z[i].clear();
			a[i].resize(m);
			z[i].resize(m);
			for (int j = 0; j < m; ++j) {
				scanf("%lld", &a[i][j]);
				if (!i) {
					z[i][j] = 0LL;
				}
			}
		}
		for (int i = 1; i < n; ++i) {
			long long plus = -oo, minus = -oo;
			for (int j = 0, m = a[i - 1].size(); j < m; ++j) {
				plus = max(plus, z[i - 1][j] + i * a[i - 1][get(j - 1, m)]);
				minus = max(minus, z[i - 1][j] - i * a[i - 1][get(j - 1, m)]);
			}
			for (int j = 0, m = a[i].size(); j < m; ++j) {
				z[i][j] = max(plus - i * a[i][j], minus + i * a[i][j]);
			}
		}
		printf("%lld\n", *max_element(z[n - 1].begin(), z[n - 1].end()));
	}
	return 0;
}
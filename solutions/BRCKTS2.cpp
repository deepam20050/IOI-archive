#include <bits/stdc++.h>

using namespace std;

string str;
int tc;
long long ans;

struct data {
	long long mx;
	long long cnt;
	long long blck;
	long long area;
	data (long long _1, long long _2, long long _3, long long _4) {
		mx = _1;
		cnt = _2;
		blck = _3;
		area = _4;
	}
};

data f (int l, int r, int d) {
	if (l + 1 == r) {
		ans += !d;
		return data(1, 1, 1, 1);
	}
	stack < int > st;
	long long mx = 0, cnt = 0, blck = 0, area = 0;
	for (int i = l; i <= r; ++i) {
		if (str[i] == '(') {
			st.push(i);
		} else {
			if (st.size() == 1) {
				int idx = st.top();
				if (idx + 1 == i) {
					mx = max(mx, 1LL);
					++cnt;
					++area;
					ans += !d;
				} else {
					data ret = f(idx + 1, i - 1, d ^ 1);
					long long mx2 = ret.mx + 1;
					long long cnt2 = ret.cnt + ret.blck + 1;
					ans += !d * (mx2 * cnt2 - ret.area);
					area += mx2 * cnt2;
					mx = max(mx, mx2);
					cnt += cnt2;
				}
				++blck;
			}
			st.pop();
		}
	}
	return data(mx, cnt, blck, area);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> str;
		stack < int > st;
		ans = 0LL;
		for (int i = 0, n = str.size(); i < n; ++i) {
			if (str[i] == '(') {
				st.push(i);
			} else {
				if (st.size() == 1) {
					int idx = st.top();
					if (idx + 1 == i) {
						++ans;
					} else {
						data ret = f(idx + 1, i - 1, 1);
						long long mx2 = ret.mx + 1;
						long long cnt2 = ret.cnt + ret.blck + 1;
						ans += mx2 * cnt2 - ret.area;
					}
				}
				st.pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
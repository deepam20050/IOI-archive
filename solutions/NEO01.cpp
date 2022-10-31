// https://www.codechef.com/problems/NEO01/
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
  	int n;
  	scanf("%d", &n);
  	vector <int> neg;
  	long long ans = 0, sum = 0, cnt = 0;
  	for (int i = 0; i < n; ++i) {
  		int x;
  		scanf("%d", &x);
  		if (x < 0) {
  			neg.push_back(-x);
  		} else {
  			sum += x;
  			++cnt;
  		}
  	}
  	ans = sum * cnt;
  	sort(neg.begin(), neg.end());
  	for (int i = 0, sz = neg.size(); i < sz; ++i) {
  		if ((sum - neg[i]) * (cnt + 1) > ans) {
  			++cnt;
  			ans = (sum - neg[i]) * cnt;
  			sum -= neg[i];
  		} else {
  			while (i < sz) {
  				ans -= neg[i];
  				++i;
  			}
  			break;
  		}
  	}
  	printf("%lld\n", ans);
  }
  return 0;
}
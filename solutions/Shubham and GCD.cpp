#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const long long LIMIT = 1e18;
const int N = 1e5 + 5;

int arr[N];
long long ans[N];
long long tmp[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		ans[i] = arr[i] != 1;
		res += ans[i];
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i + len - 1 < n; ++i) {
			ans[i] = ans[i] + ans[i + 1] + (__gcd(arr[i], arr[i + len - 1]) != 1);
			res += ans[i];
			if (res > LIMIT) {
				puts("1");
				return 0;
			}
		}
		for (int i = 0; i < n; ++i) {
			debug(ans[i]);
		}
		cout << '\n';
	}
	printf("%lld\n", res);
	return 0;
}
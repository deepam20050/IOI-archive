#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const long long p1 = 31;
const long long p2 = 41;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;

long long pw1[N];
long long pw2[N];
char str[N];
int n;
int k;
map < pair < long long, long long > , int > cnt;
map < pair < long long, long long > , int > turn;
pair < long long, long long > inp[N * N];

long long add (long long a, long long b, long long mod) { return (a + b) % mod; }
long long sub (long long a, long long b, long long mod) { return (a - b + mod) % mod; }
long long mul (long long a, long long b, long long mod) { return (a * b) % mod; }

long long compute1 () {
	long long hsh = 0LL;
	for (int i = 0; i < n; ++i) {
		hsh = add(hsh, mul(str[i], pw1[i], mod1), mod1);
	}
	return hsh;
}

long long compute2 () {
	long long hsh = 0LL;
	for (int i = 0; i < n; ++i) {
		hsh = add(hsh, mul(str[i], pw2[i], mod2), mod2);
	}
	return hsh;
}

int main() {
	pw1[0] = 1;
	pw2[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw1[i] = mul(pw1[i - 1], p1, mod1);
		pw2[i] = mul(pw2[i - 1], p2, mod2);
	}
	long long hsh1_o, hsh2_o;
	scanf("%d %d", &k, &n);
	scanf("%s", str);
	if (k == 1) {
		puts(str);
		return 0;
	}
	hsh1_o = compute1();
	hsh2_o = compute2();
	auto p = make_pair(hsh1_o, hsh2_o);
	int lel = 1;
	int lool = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (str[i] == str[j]) {
				if (turn[p] != lel) {
					++cnt[p];
					turn[p] = lel;
				}
				if (cnt[p] == k) {
					puts(str);
					return 0;
				}
				continue;
			} 
			long long hsh1 = hsh1_o, hsh2 = hsh2_o;
			hsh1 = sub(hsh1, mul(str[i], pw1[i], mod1), mod1);
			hsh1 = sub(hsh1, mul(str[j], pw1[j], mod1), mod1);
			hsh1 = add(hsh1, mul(str[j], pw1[i], mod1), mod1);
			hsh1 = add(hsh1, mul(str[i], pw1[j], mod1), mod1);

			hsh2 = sub(hsh2, mul(str[i], pw2[i], mod2), mod2);
			hsh2 = sub(hsh2, mul(str[j], pw2[j], mod2), mod2);
			hsh2 = add(hsh2, mul(str[j], pw2[i], mod2), mod2);
			hsh2 = add(hsh2, mul(str[i], pw2[j], mod2), mod2);
			inp[lool++] = {hsh1, hsh2};
		}
	}
	sort(inp, inp + lool);
	while (lel++ <= k) {
		scanf("%s", str);
		hsh1_o = compute1();
		hsh2_o = compute2();
		auto p = make_pair(hsh1_o, hsh2_o);
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (str[i] == str[j]) {
					if (turn[p] != lel) {
						++cnt[p];
						turn[p] = lel;
					}
					if (cnt[p] == k) {
						puts(str);
						return 0;
					}
					continue;
				} 
				long long hsh1 = hsh1_o, hsh2 = hsh2_o;
				hsh1 = sub(hsh1, mul(str[i], pw1[i], mod1), mod1);
				hsh1 = sub(hsh1, mul(str[j], pw1[j], mod1), mod1);
				hsh1 = add(hsh1, mul(str[j], pw1[i], mod1), mod1);
				hsh1 = add(hsh1, mul(str[i], pw1[j], mod1), mod1);

				hsh2 = sub(hsh2, mul(str[i], pw2[i], mod2), mod2);
				hsh2 = sub(hsh2, mul(str[j], pw2[j], mod2), mod2);
				hsh2 = add(hsh2, mul(str[j], pw2[i], mod2), mod2);
				hsh2 = add(hsh2, mul(str[i], pw2[j], mod2), mod2);
				auto pp = make_pair(hsh1, hsh2);
				if (binary_search(inp, inp + lool, pp)) {
					++cnt[pp];
					if (cnt[pp] == k) {
						swap(str[i], str[j]);
						puts(str);
						return 0;
					}
				}
			}
		}
	}
	puts("-1");
	return 0;
}
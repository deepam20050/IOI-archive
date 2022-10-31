#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

inline int scan(){
  char c = getchar_unlocked();
  int x = 0;
  while(c<'0'||c>'9'){
      c=getchar_unlocked();
  }
  while(c>='0'&&c<='9'){
      x=(x<<1)+(x<<3)+c-'0';
      c=getchar_unlocked();
  }
  return x;
}

int arr[N];
int occ[N];
int cnt[N];
int print[N];

int SQN;
int n;
int q;
int ans;

struct query {
	int l;
	int r;
	int id;
	int block;

	query () { }
	query (int _l, int _r, int _id) {
		l = _l;
		r = _r;
		id = _id;
		block = _id / SQN;
	}
	bool operator < (const query &b) const {
		return b.block == block ? r < b.r : block < b.block;
	}
} Q[N];

inline void add (int idx) {
	int x = arr[idx];
	--cnt[occ[x]];
	++occ[x];
	++cnt[occ[x]];
	ans = max(ans, occ[x]);
}

inline void remove (int idx) {
	int x = arr[idx];
	--cnt[occ[x]];
	--occ[x];
	++cnt[occ[x]];
	while (cnt[ans] == 0) {
		ans--;
	}
}

int main() {
	n = scan();
	q = scan();
	for (int i = 1; i <= n; ++i) {
		arr[i] = scan();
	}
	cnt[0] = n;
	SQN = sqrt(n);
	for (int i = 1; i <= q; ++i) {
		int l = scan();
		int r = scan();
		Q[i] = query(l + 1, r + 1, i);
	}
	sort(Q + 1, Q + q + 1);
	int mo_l = 1;
	int mo_r = 0;
	for (int i = 1; i <= q; ++i) {
		int l = Q[i].l;
		int r = Q[i].r;
		while (mo_r < r) {
			++mo_r;
			add(mo_r);
		}
		while (mo_l < l) {
			remove(mo_l);
			++mo_l;
		}
		while (mo_l > l) {
			--mo_l;
			add(mo_l);
		}
		while (mo_r > r) {
			remove(mo_r);
			--mo_r;
		}
		print[Q[i].id] = ans;
	}
	for (int i = 1; i <= q; ++i) {
		printf("%d\n", print[i]);
	}
	return 0;
}
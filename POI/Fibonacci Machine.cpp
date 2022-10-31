// https://szkopul.edu.pl/problemset/problem/ii2ZJ7WanCQE4DykUbqLIyVb/site/?key=statement

#include <bits/stdc++.h>

using namespace std;
using vc1 = vector < vector < int > >;
using vc2 = vector < int >;

const int N = 1e5 + 2;
const int M = 4e5 + 2;
const int mod = 1e9 + 7;

vc1 mat[N];
vc2 t[M];
int add[M];
int n;
int q;

// FAST IO TAKEN FROM -> https://drive.google.com/file/d/0B_AmrhcPa4HbQ2FWQWdaMGsxMjQ/view

/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

inline void mat_mul (vc1 &res, const vc1 &a, const vc1 &b) {
	res = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				res[i][j] += (1LL * a[i][k] * b[k][j]) % mod;
				if (res[i][j] >= mod) {
					res[i][j] -= mod;
				}
			}
		}
	}
}

inline vc2 vec_mul (const vc1 &a, const vc2 &b) {
	vc2 res = {0, 0};
	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k) {
			res[i] += (1LL * a[i][k] * b[k]) % mod;
			if (res[i] >= mod) {
				res[i] -= mod;
			}
		}
	}
	return res;
}

inline void build_mat () {
	mat[0] = {{1, 0}, {0, 1}};
	mat[1] = {{0, 1}, {1, 1}};
	for (int i = 2; i < N; ++i) {
		mat_mul(mat[i], mat[i - 1], mat[1]);
	}
}

inline void join (int node) {
	vc2 lftsum = vec_mul(mat[add[node << 1]], t[node << 1]);
	vc2 rgtsum = vec_mul(mat[add[node << 1 | 1]], t[node << 1 | 1]);
	int sum1 = lftsum[0] + rgtsum[0];
	if (sum1 >= mod) {
		sum1 -= mod;
	}
	int sum2 = lftsum[1] + rgtsum[1];
	if (sum2 >= mod) {
		sum2 -= mod;
	}
	t[node] = {sum1, sum2};
}

inline void push (int node, int l, int r) {
	if (!add[node]) {
		return;
	}
	t[node] = vec_mul(mat[add[node]], t[node]);
	if (l == r) {
		add[node] = 0;
		return;
	}
	add[node << 1] += add[node];
	add[node << 1 | 1] += add[node];
	add[node] = 0;
}

void build (int node, int l, int r) {
	if (l == r) {
		t[node] = {0, 1};
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	join(node);
}

void update (int node, int l, int r, int x, int y) {
	push(node, l, r);
	if (x <= l && r <= y) {
		++add[node];
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x, y);
	}
	if (y > m) {
		update(node << 1 | 1, m + 1, r, x, y);
	}
	push(node << 1, l, m);
	push(node << 1 | 1, m + 1, r);
	join(node);
}

int query (int node, int l, int r, int x, int y) {
	push(node, l, r);
	if (x <= l && r <= y) {
		return t[node][0];
	}
	int ret = 0;
	int m = l + r >> 1;
	if (x <= m) {
		ret += query(node << 1, l, m, x, y);
	}
	if (y > m) {
		ret += query(node << 1 | 1, m + 1, r, x, y);
	}
	return ret >= mod ? ret - mod : ret;
}

int main() {
	build_mat();
	n = readInt();
	q = readInt();
	build(1, 1, n);
	while (q--) {
		char ch = readChar();
		int l = readInt();
		int r = readInt();
		if (ch == 'D') {
			update(1, 1, n, l, r);
		} else {
			writeInt(query(1, 1, n, l, r), '\n');
		}
	}
	return 0;
}
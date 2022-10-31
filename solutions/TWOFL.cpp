// https://www.codechef.com/JUNE18B/problems/TWOFL/
// FAST IO taken from -> https://drive.google.com/file/d/0B_AmrhcPa4HbQ2FWQWdaMGsxMjQ/view

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 2;
const int M = 4e6 + 2;
const int oo = 1 << 29;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};


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

int arr[N][N];
int color[N][N];
int n;
int m;
int clr_idx;
int ed_idx;
int clr_cnt[M];
vector < pair < pair < int, int >, pair < int, int > > > edge;
bool vis[N][N];
bool used[M];
int p[M];
int ans[M];
int sz[M];
int cnt;
int fst;
int lst;
int res;
int where[M];
int curr;

inline bool check (int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs1 (int x, int y) {
  color[x][y] = clr_idx;
  ++cnt;
  for (int i = 0; i < 4; ++i) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (check(x0, y0) && arr[x0][y0] == arr[x][y] && !color[x0][y0]) {
      dfs1(x0, y0);
    }
  }
}

void dfs2 (int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (check(x0, y0)) {
      if (arr[x0][y0] != arr[x][y]) {
        edge.push_back({{min(arr[x0][y0], arr[x][y]), max(arr[x0][y0], arr[x][y])}, {min(color[x0][y0], color[x][y]), max(color[x0][y0], color[x][y])}});
      }
      if (arr[x0][y0] == arr[x][y] && !vis[x0][y0]) {
        dfs2(x0, y0);
      }
    }
  }
}

inline void build () {
  n = readInt();
  m = readInt();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = readInt();
    }
  }
  clr_idx = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
     if (!color[i][j]) {
        cnt = 0;
        dfs1(i, j);
        clr_cnt[clr_idx] = cnt;
        p[clr_idx] = clr_idx;
        sz[clr_idx] = 1;
        ans[clr_idx] = cnt;
        res = max(res, cnt);
        ++clr_idx;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[color[i][j]]) {
        dfs2(i, j);
      }
    }
  }
  sort(edge.begin(), edge.end());
}

inline int find_set (int x) {
  return p[x] == x ? x : p[x] = find_set(p[x]);
}

inline void join (int x, int y) {
  if (where[x] != curr) {
    p[x] = x;
    sz[x] = 1;
    ans[x] = clr_cnt[x];
    where[x] = curr;
  }
  if (where[y] != curr) {
    p[y] = y;
    sz[y] = 1;
    ans[y] = clr_cnt[y];
    where[y] = curr;
  }
  x = find_set(x);
  y = find_set(y);
  if (x == y) {
    return;
  }
  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  sz[x] += sz[y];
  ans[x] += ans[y];
  p[y] = x;
  res = max(ans[x], res);
}

int main() {
  build();
  int a = -1;
  int b = -1;
  fst = 0;
  lst = -1;
  curr = 1;
  edge.push_back({{oo, oo}, {oo, oo}});
  ed_idx = edge.size();
  for (int i = 0; i < ed_idx; ++i) {
    int clr_a = edge[i].first.first;
    int clr_b = edge[i].first.second;
    int u = edge[i].second.first;
    int v = edge[i].second.second;
    if (clr_a == a && clr_b == b) {
      join(u, v);
      lst = i;  
      continue;
    }
    fst = i;
    lst = i;
    a = clr_a;
    b = clr_b;
    ++curr;
    if (i + 1 != ed_idx) {
      join(u, v);
    }
  }
  writeInt(res, '\n');
  return 0;
}
// https://www.codechef.com/problems/REVERSE
// AC

#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;

const int N = 1e5+5;
const int INF = 1e9;

vector <int> fo[N], rev[N];
priority_queue <pi, vector<pi>, greater<pi>> pq;
vector <int> d(N,INF);

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 0; i < m; ++i) {
		int x,y;
		scanf("%d %d",&x,&y);
		fo[x].emplace_back(y);
		rev[y].emplace_back(x);
	}

	d[1] = 0;
	pq.push({0,1});

	while (!pq.empty()) {
		int w = pq.top().first, u = pq.top().second;
		pq.pop();

		for (auto &e: fo[u]) {
			if (d[e] > w) {
				d[e] = w;
				pq.push({d[e], e});
			}
		}

		for (auto &e: rev[u]) {
			if (d[e] > w + 1) {
				d[e] = w + 1;
				pq.push({d[e], e});
			}
		}
	}

	printf("%d\n",(d[n] == INF ? -1 : d[n]));

	return 0;
}
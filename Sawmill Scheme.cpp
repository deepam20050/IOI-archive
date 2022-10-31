// https://dmoj.ca/problem/dmopc14c2p5
// Partially correct

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

vector <int> g[N];
bool used[N];
double prob[N];
vector <int> v;
queue <int> q;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
	}
	q.push(1);
	prob[1] = 1;
	while (!q.empty()) {
		int x = q.front(); 
		q.pop();
		used[x] = 1;
		for (const auto &e: g[x]) {
			prob[e] += prob[x]/(double)g[x].size();
			if (!used[e]) {
				q.push(e);
			}
		}
		if (g[x].empty()) {
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	for (const auto &e: v) {
		printf("%.9f\n", prob[e]);
	}
	return 0;
}
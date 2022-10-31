// http://codeforces.com/problemset/problem/274/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

long ar[N];
vector <long> s1, s2;

int main() {
	int n,k;
	scanf("%d %d",&n,&k);

	for (int i = 0; i < n; ++i) {
		scanf("%ld",&ar[i]);
	}

	sort(ar,ar+n);

	for (int i = 0; i < n; ++i) {
		bool state = binary_search(ar,ar+n,ar[i] * k);
		if (state && !binary_search(s2.begin(), s2.end(),ar[i])) {
			s2.emplace_back(ar[i] * k);
		}
		if (ar[i] % k == 0 && !binary_search(s1.begin(), s1.end(), ar[i] / k)) {
			s1.emplace_back(ar[i]); 
		} else if (ar[i] % k) {
			s1.emplace_back(ar[i]);
		}
	}

	printf("%d\n",(int)max(s1.size(),s2.size()));

	return 0;
}

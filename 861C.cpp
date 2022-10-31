// http://codeforces.com/contest/861/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 3456;

char s[N];
bool sp[N];

bool isv(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		return 1;
	} 
	return 0;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		string t;
		for (int j = 0; j < 3; ++j) {
			t += s[i + j];
		}
		if (t.size() == 3) {
			if (!isv(t[0]) && !isv(t[1]) && !isv(t[2])) {
				set <int> st;
				st.insert(t[0]);
				st.insert(t[1]);
				st.insert(t[2]);
				if (st.size() != 1) {
					sp[i + 1] = 1;
					++i;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%c", s[i]);
		if (sp[i]) {
			printf(" ");
		}
	}
	return 0;
}
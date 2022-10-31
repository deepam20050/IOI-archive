// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/

#include <bits/stdc++.h>

using namespace std;

struct trie {
	int mx;
	trie *child[26];
};

string tmp;
int val;
int n;
int q;

trie *getnode () {
	trie *res = new trie;
	res->mx = -1;
	for (int i = 0; i < 26; ++i) {
		res->child[i] = nullptr;
	}
	return res;
}

void insert (trie *root) {
	trie *curr = root;
	for (int i = 0; i < tmp.size(); ++i) {
		int idx = tmp[i] - 'a';
		if (curr->child[idx] == nullptr) {
			curr->child[idx] = getnode();
		}
		curr->mx = max(curr->mx, val);
		curr = curr->child[idx];
		curr->mx = max(curr->mx, val);
	}
	if (curr == nullptr) return;
	curr->mx = max(curr->mx, val);
}

int query (trie *root) {
	trie *curr = root;
	for (int i = 0; i < tmp.size(); ++i) {
		int idx = tmp[i] - 'a';
		if (curr->child[idx] == nullptr) {
			return -1;
		}
		curr = curr->child[idx];
	}
	return curr->mx;
}

trie *root = getnode();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> tmp >> val;
		insert(root);
	}
	while (q--) {
		cin >> tmp;
		cout << query(root) << '\n';
	}
	return 0;
}
// https://www.codechef.com/MAY17/problems/WSITES01
// AC
// Trie Data structure

#include <bits/stdc++.h>

using namespace std;

struct node {
  node *child[26];
};

node *getnode() {
  node *res = nullptr;
  res = new node;
  if (!res) {
   return res;
  }
  for (int i = 0; i < 26; ++i) {
    res->child[i] = nullptr;
  }
  return res;
}

void insert(const string &s, node *root) {
  node *ptr = root;
  for (int i = 0, sz = s.size(); i < sz; ++i) {
    int idx = s[i] - 'a';
    if (ptr->child[idx] == nullptr) {
      ptr->child[idx] = getnode();
    }
    ptr = ptr->child[idx];
  }
}

string prefix(const string &s, node *root) {
  string res;
  node *ptr = root;
  int i = 0, sz = s.size();
  for (; i < sz; ++i) {
    res += s[i];
    int idx = s[i] - 'a';
    if (ptr->child[idx] == nullptr) {
      break;
    }
    ptr = ptr->child[idx];
  }
  if (i == sz) {
    for (int i = 0; i < 26; ++i) {
      if (ptr->child[i]) {
        return string("-1");
      }
    }
  }
  return res;
}

vector <string> block;

node *root = getnode();

int main() {
  int n;
  scanf("%d", &n); 
  for (int i = 0; i < n; ++i) {
    char c;
    string s;
    cin >> c >> s;
    if (c == '+') {
      insert(s, root);
    } else {
      block.emplace_back(s);
    }
  }
  set <string> st;
  for (const auto &e: block) {
    string res = prefix(e, root); 
    if (res != "-1") {
      st.insert(prefix(e, root));
    } else {
      return !printf("-1");
    }
  }
  if (st.empty()) {
    return !printf("-1");
  }
  printf("%d\n", (int)st.size());
  for (const auto &e: st) {
    cout << e << '\n';
  }
  return 0;
}

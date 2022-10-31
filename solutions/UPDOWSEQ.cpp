#include <bits/stdc++.h>

using namespace std;

int main() {
  set < int > st;
  st.insert(5);
  st.insert(6);
  st.insert(7);
  auto it1 = st.find(5);
  auto it2 = st.find(7);
  cout << it2 - it1 << '\n';
  return 0;
}
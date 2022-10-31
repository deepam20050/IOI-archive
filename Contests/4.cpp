#include <bits/stdc++.h>

using namespace std;

int arr[] = {1, 3, 4, 5};
  int brr[] = {2, 3, 4, 5};

bool check () {
  for (int i = 0; i < 4; ++i) {
    if (arr[i] == brr[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int c = 24;
  do {
    c -= check();
  } while (next_permutation(brr, brr + 4));
  cout << c << '\n';
  return 0;
}
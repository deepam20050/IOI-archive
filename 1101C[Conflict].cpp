#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &arr[i].first.first, &arr[i].first.second);
      arr[i].second = i;
    }
    sort(arr, arr + n);
    bool ok = 1, ok1 = 0, ok2 = 0;
    for (int i = 1; i < n; ++i) {
      if (arr[i].first.first == arr[i - 1].first.second || (arr[i].first.first == arr[i - 1].first.first && arr[i].first.second == arr[i - 1].first.second)) {
        ok = 0;
        break;
      }
      if (arr[i - 1].first.first < arr[i].first.frist && arr[i].first.first < arr[i - 1].first.second) {
        who[arr[i].second] = 3 - who[arr[i - 1].first];
      } else {
        who[arr[i].second] = who[arr[i - 1].first];
      }
      where[who[arr[i].second]].push_back(i);
    }
  }
  return 0;
}
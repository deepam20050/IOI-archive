// https://dmoj.ca/problem/ccc03s4

#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

string s;

int main() {
  int t;
  scan(t);
  while (t--) {
    cin >> s;
    int n = s.size();
    int ans = 2;
    for (int len = 1; len < n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        string check = s.substr(i, len);
        if (s.find(check) == i) {
          ++ans;
        }
      }
    }
    writeInt(ans);
    puts("");
  }
  return 0;
}
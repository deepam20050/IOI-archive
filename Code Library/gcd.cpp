template <typename T>
inline T gcd (T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
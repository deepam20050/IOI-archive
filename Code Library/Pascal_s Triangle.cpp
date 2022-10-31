inline void calc_pascal (const long long &mod, const int &SZ) {
  for (int i = 0; i < SZ; ++i){
    pascal[i][0] = 1LL;
    for (int j = 1; j <= i; ++j){
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
      pascal[i][j] -= (pascal[i][j] >= mod) * mod; 
    }
  }
}
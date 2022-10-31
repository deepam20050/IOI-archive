
#include <stdio.h>

#define MAX_N 1000

int n,s;
int p[MAX_N],x[MAX_N];

FILE *fp;

void read_input(void)
{
  int i;

  // reading from "CARDS.IN"

  fp = fopen("CARDS.IN","rt");

  fscanf(fp,"%d %d\n",&n,&s);

  for (i = 0;i < n;++i)
  {
    fscanf(fp,"%d\n",p + i);
    --p[i];
  }

  fclose(fp);
}

void solve(void)
{
  int i,j;
  int s2,sol;
  int temp[MAX_N];

  // calculating number "s2", 2 to the power of "s" modulo "n"

  s2 = 1;

  for (i = 0;i < s;++i)
    s2 = (2 * s2) % n;

  // calculating number "sol", such that "sol" * "s2" modulo "n" is 1

  for (i = 1;i <= n - 1;++i)
  {
    if (((long) i) * s2 % n == 1)
    {
      sol = i;
      break;
    }
  }

  // calculating permutation "x", "p" to the power of "sol"

  for (i = 0;i < n;++i)
    x[i] = i;

  for (i = 0;i < sol;++i)
  {
    for (j = 0;j < n;++j)
      temp[j] = p[x[j]];
    for (j = 0;j < n;++j)
      x[j] = temp[j];
  }

}

void write_output(void)
{
  int i;

  // writing to "CARDS.OUT"

  fp = fopen("CARDS.OUT","wt");

  for (i = 0;i < n;++i)
    fprintf(fp,"%d\n",x[i] + 1);

  fclose(fp);
}

int main(void)
{
  read_input();

  solve();

  write_output();

  return 0;
}

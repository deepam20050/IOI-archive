def integers () :
  return map(int,input().split())

n, m = integers()
coins = []
for i in range(n) :
  p, c = integers()
  if (p != 1) :
    coins.append(c)
coins.sort()
if len(coins) < n - len(coins) :
  print(0)
else :
  div = n // 2 + 1
  add = 0
  for i in range(div) :
    add += coins[i]
  print(add)

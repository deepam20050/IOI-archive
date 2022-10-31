# http://codeforces.com/problemset/problem/950/C

s = input()
v = []
for x in range (200000) :
  v.append([])
idx = 0
pos = 0
sz = 0
for x in s : 
  if (x == '0') :
    v[idx].append(pos + 1)
    idx += 1
  else :
    if (idx == 0) :
      print("-1")
      exit()
    idx -= 1
    v[idx].append(pos + 1)
  pos += 1
  sz = max(sz, idx)
if (sz != idx) : 
  print("-1")
  exit()
print (idx)
at = 0
while (at < idx) : 
  print (len(v[at]), end = " ")
  att = 0
  for x in v[at] :
    print (x, end = " ")
  at += 1
  print("")
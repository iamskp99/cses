from itertools import combinations
from bisect import bisect_left
import sys
import math
input = sys.stdin.readline

n,x = map(int,input().split())
l = list(map(int,input().split()))
w1 = []
w2 = []
for i in range(n):
    if i < n//2:
        w1.append(l[i])

    else:
        w2.append(l[i])

d1 = {}
d2 = {}
for i in range(1,len(w1)+1):
    for c in combinations(w1,i):
        som = 0
        for g in c:
            som += g

        if som in d1:
            d1[som] += 1

        else:
            d1[som] = 1

for i in range(1,len(w2)+1):
    for c in combinations(w2, i):
        som = 0
        for g in c:
            som += g

        if som in d2:
            d2[som] += 1

        else:
            d2[som] = 1

ans = 0
for i in d1:
    if i == x:
        ans += d1[i]

    else:
        to = x-i
        if to in d2:
            ans += (d2[to]*d1[i])

for i in d2:
    if i == x:
        ans += d2[i]

sys.stdout.write(str(ans))
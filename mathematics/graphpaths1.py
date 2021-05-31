M = (10**9)+7
n,m,k = map(int,input().split())
d = {}
for i in range(m):
    a,b = map(int,input().split())
    if a in d:
        d[a].append(b)

    else:
        d[a] = [b]


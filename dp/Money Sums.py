n = int(input())
l = list(map(int, input().split()))
ans = set()
i = 0
while i < n:
    a = []
    a.append(l[i])
    j = 0
    for j in ans:
        a.append(j + l[i])

    for e in a:
        ans.add(e)

    i = i + 1

s = list(ans)
s.sort()
print(len(s))
print(*s)
n = int(input())
if n == 1:
    print(1)
    exit()

if n == 4:
    print(2,4,1,3)
    exit()

if n < 4:
    print("NO SOLUTION")

else:
    d = []
    for i in range(1,(n//2)+1):
        d.append(i)

    o = []
    x = (n//2)+1
    if n%2 == 1:
        o.append((n//2)+1)
        x = (n//2)+2

    p = []
    for i in range(x,n+1):
        p.append(i)

    ans = []
    p.sort(reverse = True)
    p1 = 0
    while p1 < n//2:
        ans.append(p[p1])
        ans.append(d[p1])
        p1 += 1

    w = ans+o
    w[-1],w[0] = w[0],w[-1]
    print(*w)
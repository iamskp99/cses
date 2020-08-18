n = int(input())
cnt = 0
while(n > 0):
    l = []
    for i in str(n):
        l.append(int(i))

    m = max(l)
    n = n-m
    cnt = cnt+1

print(cnt)

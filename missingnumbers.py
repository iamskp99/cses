n = int(input())
l = list(map(int,input().split()))
s = set(l)
for i in range(1,n+1):
    if i not in s:
        print(i)
        break
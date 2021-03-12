n = int(input())
l = []
l.append(n)

while (n != 1):
    if n % 2 == 0:
        n = n // 2

    else:
        n = (n * 3) + 1

    l.append(n)

print(*l)
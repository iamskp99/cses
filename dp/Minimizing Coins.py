import sys

input = sys.stdin.readline
n, x = map(int, input().split())
l = list(map(int, input().split()))
dp = [-1] * (x + 1)
dp[0] = 0
for i in range(1, x + 1):
    ans = 10 ** 7
    for j in l:
        if j <= i:
            ans = min(ans, dp[i - j])

    dp[i] = ans + 1

ans = dp[-1]
if dp[-1] >= 10 ** 7:
    ans = -1

print(ans)
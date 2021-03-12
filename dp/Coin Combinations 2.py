M = 1000000007
import sys

input = sys.stdin.readline
n, x = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
dp = [0 for i in range(x + 1)]
dp[0] = 1
for j in l:
    for i in range(1, x + 1):
        if i - j < 0:
            continue

        else:
            if dp[i - j] > 0:
                dp[i] = (dp[i] + dp[i - j]) % M

sys.stdout.write(str(dp[x]))
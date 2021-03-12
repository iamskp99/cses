# Iterative code
M = 1000000007
import sys

input = sys.stdin.readline
n, x = map(int, input().split())
l = list(map(int, input().split()))
dp = [0 for i in xrange(x + 1)]
dp[0] = 1
for i in xrange(1, x + 1):
    ans = 0
    for j in l:
        if i - j < 0:
            continue

        else:
            if dp[i - j] > 0:
                ans += (dp[i - j]) % M

    dp[i] = ans % M

sys.stdout.write(str(dp[x]))

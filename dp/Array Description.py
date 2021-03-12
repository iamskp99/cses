# Iterative code
M = (10 ** 9) + 7
n, m = map(int, input().split())
l = list(map(int, input().split()))
dp = [[0 for i in range(m + 1)] for j in range(n)]
i = n - 1
while i > -1:
    if l[i] == 0:
        if i == n - 1:
            for j in range(1, m + 1):
                dp[i][j] = 1 % M

        else:
            for j in range(1, m + 1):
                for k in range(j - 1, j + 2):
                    if k > 0 and k < m + 1:
                        dp[i][j] = (dp[i][j] + dp[i + 1][k]) % M

    else:
        if i == n - 1:
            dp[i][l[i]] = 1 % M

        else:
            for k in range(l[i] - 1, l[i] + 2):
                if k > 0 and k < m + 1:
                    dp[i][l[i]] = (dp[i][l[i]] + dp[i + 1][k]) % M

    i -= 1

ans = 0
for i in range(1, m + 1):
    ans = (ans + dp[0][i]) % M

# print(dp)
print(ans)

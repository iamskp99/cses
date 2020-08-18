M = 10**9+7
n = int(input())
dp = [0]*(n+1)
dp[0] = 1
for i in range(1,n+1):
    for j in range(1,6+1):
        if i-j >= 0:
            dp[i] = (dp[i]+dp[i-j])%M

        else:
            break

print(dp[-1]%M)
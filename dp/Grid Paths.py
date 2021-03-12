# Recursive code
M = 1000000007
import sys

input = sys.stdin.readline
# Recursion support template
import sys

input = sys.stdin.readline
from types import GeneratorType


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


@bootstrap
def rec(i, j):
    if i == n or j == n:
        yield 0

    if dp[i][j] != -1:
        yield dp[i][j]

    if i == n - 1 and j == n - 1 and p[i][j] != "*":
        dp[i][j] = 1
        yield dp[i][j]

    if p[i][j] == "*":
        dp[i][j] = 0
        yield dp[i][j]

    a = yield rec(i + 1, j)
    b = yield rec(i, j + 1)
    dp[i][j] = (a + b) % M
    yield dp[i][j]


n = int(input())
p = []
for i in range(n):
    s = input()
    p.append(s)

dp = [[-1 for j in range(n)] for i in range(n)]
print(rec(0, 0))
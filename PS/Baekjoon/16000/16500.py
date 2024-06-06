from collections import defaultdict

S = input()
N = int(input())

arr, dp = [], [False for i in range(len(S) + 1)]

for i in range(N):
    arr.append(input())

dp[0] = True
for i in range(len(S)):
    if not dp[i]:
        continue

    for j in arr:
        if i + len(j) <= len(S):
            if S[i : i + len(j)] == j:
                dp[i + len(j)] = True

print(int(dp[len(S)]))

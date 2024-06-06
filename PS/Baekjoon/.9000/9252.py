A = " " + input()
B = " " + input()

dp = [[(0, "") for j in range(len(B))] for i in range(len(A))]

for i in range(1, len(A)):
    for j in range(1, len(B)):
        if A[i] == B[j]:
            dp[i][j] = (dp[i - 1][j - 1][0] + 1, dp[i - 1][j - 1][1] + A[i])
        else:
            dp[i][j] = dp[i - 1][j] if dp[i - 1][j][0] >= dp[i][j - 1][0] else dp[i][j - 1]

print("\n".join(map(str, dp[len(A) - 1][len(B) - 1])))

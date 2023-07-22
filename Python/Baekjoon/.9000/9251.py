A = input()
B = input()

dp = [[0 for j in range(len(B))] for i in range(len(A))]
mx = 0

for i in range(len(A)):
    for j in range(len(B)):
        if i >= 1:
            dp[i][j] = max(dp[i][j], dp[i - 1][j])
        if j >= 1:
            dp[i][j] = max(dp[i][j], dp[i][j - 1])

        if A[i] == B[j]:
            if i >= 1 and j >= 1:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
            else:
                dp[i][j] = 1

print(dp[len(A) - 1][len(B) - 1])

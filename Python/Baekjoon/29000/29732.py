N, M, K = map(int, input().split())
S = ["."] + list(input())

new_S = S.copy()

for i in range(1, N + 1):
    if S[i] == "R":
        for j in range(max(1, i - K), min(N, i + K) + 1):
            new_S[j] = "R"

print("Yes" if new_S.count("R") <= M else "No")

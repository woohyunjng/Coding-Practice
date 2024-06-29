N = int(input())
S = input()

MOD = 10**9 + 7
res = 1

arr = [1]

for i in range(1, N):
    if S[i] == S[i - 1]:
        arr.append(1)
    else:
        arr[-1] += 1

for i in arr:
    res = res * ((i + 1) // 2) % MOD

print(res)

N, M = map(int, input().split())
A = list(map(int, input().split()))
A_sum = [0]
mod = [0 for i in range(M)]
mod[0] += 1

for i in range(N):
    A_sum.append(A_sum[-1] + A[i])
    mod[A_sum[i + 1] % M] += 1

res = 0
for i in range(M):
    res += mod[i] * (mod[i] - 1) // 2

print(res)

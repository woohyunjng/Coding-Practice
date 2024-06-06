N = int(input())
min_arr, pls_arr = [], []

for i in range(N):
    A = int(input())
    if A <= 0:
        min_arr.append(A)
    else:
        pls_arr.append(A)

min_arr = list(sorted(min_arr))
pls_arr = list(sorted(pls_arr, reverse=True))

res = (min_arr[-1] if len(min_arr) % 2 else 0) + (
    pls_arr[-1] if len(pls_arr) % 2 else 0
)
for i in range(len(min_arr) // 2):
    res += min_arr[2 * i] * min_arr[2 * i + 1]

for i in range(len(pls_arr) // 2):
    if pls_arr[2 * i] != 1 and pls_arr[2 * i + 1] != 1:
        res += pls_arr[2 * i] * pls_arr[2 * i + 1]
    else:
        res += pls_arr[2 * i] + pls_arr[2 * i + 1]

print(res)

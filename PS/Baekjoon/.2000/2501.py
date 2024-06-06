arr = []
N, K = map(int, input().split())

for i in range(1, int(N**0.5) + 1):
    if N % i:
        continue

    if i**2 == N:
        arr.append(i)
    else:
        arr.append(i)
        arr.append(N // i)

arr = list(sorted(arr))
print(arr[K - 1] if K <= len(arr) else 0)

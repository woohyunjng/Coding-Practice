N = int(input())
arr = list(sorted(map(int, input().split())))

mn = 1e10
A, B, C = -1, -1, -1

for i in range(1, N - 1):
    j, k = 0, N - 1
    while j < i and i < k:
        sm = arr[i] + arr[j] + arr[k]
        if abs(sm) < mn:
            mn = abs(sm)
            A, B, C = j, i, k

        if sm > 0:
            k -= 1
        elif sm < 0:
            j += 1
        else:
            break

print(arr[A], arr[B], arr[C])

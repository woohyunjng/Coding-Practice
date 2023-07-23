N = int(input())
C = list(map(int, input().split()))

res = sum(C)
arr, before = [], False

for i in range(N):
    if C[i]:
        before = False
        continue

    if before:
        arr[-1] += 1
    else:
        arr.append(1)
    before = True

if len(arr) == 1 and not C[-1] and not C[0]:
    print(arr[0] // 2)
    exit()

if not C[-1] and not C[0]:
    arr[0] += arr.pop()

for i in arr:
    res += (i + 1) // 2

print(res)

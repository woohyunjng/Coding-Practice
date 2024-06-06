N = int(input())
arr = []

for i in range(N):
    arr.append(input())
    if arr[-1] == "?":
        k = i

M = int(input())
A = []

for i in range(M):
    A.append(input())

if N == 1:
    print(A[0])
    exit()

for i in A:
    if i in arr:
        continue

    if not k:
        if i.endswith(arr[k + 1][0]):
            print(i)
            break
    elif k == N - 1:
        if i.startswith(arr[k - 1][-1]):
            print(i)
            break
    else:
        if i.startswith(arr[k - 1][-1]) and i.endswith(arr[k + 1][0]):
            print(i)
            break

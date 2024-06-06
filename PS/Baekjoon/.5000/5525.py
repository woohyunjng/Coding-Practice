N = int(input())
M = int(input())
S = input()

arr, lst = [[0, S[0] == "I"]], S[0]

for i in S:
    if i == lst:
        lst = "I" if lst == "O" else "O"
        arr[-1][0] += 1
    else:
        arr.append([1, i == "I"])

res = 0
for i in range(len(arr)):
    if not arr[i][1]:
        arr[i] = arr[i][0] - 1
    else:
        arr[i] = arr[i][0]

    if arr[i] < 2 * N + 1:
        continue
    else:
        res += (arr[i] - (2 * N + 1)) // 2 + 1

print(res)

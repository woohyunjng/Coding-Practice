S = input()
arr = [S[0]]

for i in range(1, len(S)):
    if S[i] in ["+", "-"]:
        arr[-1] = int(arr[-1])
        arr.append(S[i])
        arr.append("")
    else:
        arr[-1] += S[i]
arr[-1] = int(arr[-1])


res, i = 0, 0
while i < len(arr):
    if arr[i] == "+":
        res += arr[i + 1]
        i += 2
    elif arr[i] == "-":
        i += 1
        while i < len(arr):
            if arr[i] == "+":
                res -= arr[i + 1]
                i += 2
            elif arr[i] == "-":
                break
            else:
                res -= arr[i]
                i += 1
    else:
        res += arr[i]
        i += 1

print(res)

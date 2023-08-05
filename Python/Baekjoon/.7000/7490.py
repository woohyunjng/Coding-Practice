def get(N, i):
    if i == N:
        return [str(N)]

    arr = []
    new_arr = get(N, i + 1)

    for j in ["+", "-", " "]:
        for k in new_arr:
            arr.append(f"{i}{j}{k}")

    return arr


T = int(input())
for i in range(T):
    N = int(input())
    arr = get(N, 1)
    res = []

    for j in arr:
        if eval(j.replace(" ", "")) == 0:
            res.append(j)

    for j in sorted(res):
        print(j)
    print()

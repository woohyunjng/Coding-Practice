while True:
    N = int(input())
    if N < 0:
        break

    arr = []

    for i in range(1, int(N**0.5) + 1):
        if N % i:
            continue

        if i**2 == N:
            arr.append(i)
        else:
            arr.append(i)
            arr.append(N // i)

    arr = list(sorted(arr))[:-1]
    if sum(arr) == N:
        print(f"{N} = {' + '.join(map(str, arr))}")
    else:
        print(f"{N} is NOT perfect.")

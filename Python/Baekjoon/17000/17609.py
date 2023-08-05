T = int(input())
for i in range(T):
    S = input()
    (
        i,
        j,
    ) = (
        0,
        len(S) - 1,
    )

    while i <= j:
        if S[i] != S[j]:
            break
        i += 1
        j -= 1
    else:
        print(0)
        continue

    ip = False

    (
        i,
        j,
    ) = (
        0,
        len(S) - 1,
    )
    while i <= j:
        if S[i] != S[j] and (i + j != len(S) - 1):
            break
        elif S[i] != S[j]:
            i += 1
        else:
            i += 1
            j -= 1
    else:
        ip = True

    (
        i,
        j,
    ) = (
        0,
        len(S) - 1,
    )
    while i <= j:
        if S[i] != S[j] and (i + j != len(S) - 1):
            break
        elif S[i] != S[j]:
            j -= 1
        else:
            i += 1
            j -= 1
    else:
        ip = True

    if ip:
        print(1)
    else:
        print(2)

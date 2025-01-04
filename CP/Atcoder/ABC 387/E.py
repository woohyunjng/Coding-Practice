N = input()
L = len(N)

K = int(N[0])

if K == 5:
    print("8" + "0" * (L - 1))
elif K >= 6:
    if L == 1:
        print(9)
    else:
        print("1" + "0" * (L - 2) + "10")
elif K == 1:
    if N == "1" + "0" * (L - 1):
        if L == 1:
            print(1)
        elif L == 2:
            print(-1)
        else:
            print("1" + "0" * (L - 3) + "10")
    else:
        print("2" + "0" * (L - 1))
elif K == 4:
    if N == "4" + "0" * (L - 1):
        if L == 1:
            print(4)
        elif L == 2:
            print(-1)
        else:
            print("4" + "0" * (L - 3) + "40")
    else:
        print("8" + "0" * (L - 1))
elif K == 3:
    if L == 1:
        print(3)
    elif L == 2:
        print(-1)
    else:
        print("4" + "0" * (L - 3) + "40")
else:
    if L == 1:
        print(2)
    elif L == 2:
        if N == "20":
            print(20)
        else:
            print(-1)
    elif L == 3:
        print(399)
    else:
        print("3" + "0" * (L - 3) + "32")

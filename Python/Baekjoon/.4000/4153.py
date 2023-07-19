while True:
    a = map(int, input().split())
    a = list(sorted(a))

    if a == [0, 0, 0]:
        break

    if a[0] ** 2 + a[1] ** 2 == a[2] ** 2:
        print("right")
    else:
        print("wrong")

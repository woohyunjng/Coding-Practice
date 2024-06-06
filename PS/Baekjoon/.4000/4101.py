while True:
    A, B = map(int, input().split())
    if not A:
        break

    print("Yes" if A > B else "No")

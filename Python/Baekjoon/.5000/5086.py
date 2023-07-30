while True:
    a, b = map(int, input().split())
    if not (a + b):
        break

    if not b % a:
        print("factor")
    elif not a % b:
        print("multiple")
    else:
        print("neither")

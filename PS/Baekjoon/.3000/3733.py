while True:
    try:
        A, B = map(int, input().split())
        print(B // (A + 1))
    except:
        break

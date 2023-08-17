arr = [
    (0, 1),
    (0, 3),
    (0, 5),
    (0, 7),
    (1, 0),
    (1, 2),
    (1, 4),
    (1, 6),
    (1, 8),
    (2, 1),
    (2, 3),
    (2, 5),
    (2, 7),
    (2, 9),
    (3, 0),
    (3, 2),
    (3, 4),
    (3, 6),
    (3, 8),
    (4, 1),
    (4, 3),
    (4, 5),
    (4, 7),
    (4, 9),
    (5, 0),
    (5, 2),
    (5, 4),
    (5, 6),
    (5, 8),
    (6, 1),
    (6, 3),
    (6, 5),
    (6, 7),
    (6, 9),
    (7, 0),
    (7, 2),
    (7, 4),
    (7, 6),
    (7, 8),
    (8, 1),
    (8, 3),
    (8, 5),
    (8, 7),
    (8, 9),
    (9, 2),
    (9, 4),
    (9, 6),
    (9, 8),
]

for i, j in arr:
    print("?", i, j, flush=True)
    check = bool(int(input()))

    if check:
        if i == 0:
            for x, y in [(i, j - 1), (i, j + 1), (i + 1, j)]:
                print("?", x, y, flush=True)
                check_another = bool(int(input()))
                if check_another:
                    print("!", i, j, x, y, flush=True)
                    break
        elif i == 9:
            for x, y in [(i, j - 1), (i, j + 1)]:
                print("?", x, y, flush=True)
                check_another = bool(int(input()))
                if check_another:
                    print("!", i, j, x, y, flush=True)
                    break
            else:
                print("!", i, j, i - 1, j, flush=True)
        elif j == 0:
            for x, y in [(i - 1, j), (i + 1, j), (i, j + 1)]:
                print("?", x, y, flush=True)
                check_another = bool(int(input()))
                if check_another:
                    print("!", i, j, x, y, flush=True)
                    break
        elif j == 9:
            for x, y in [(i - 1, j), (i + 1, j), (i, j - 1)]:
                print("?", x, y, flush=True)
                check_another = bool(int(input()))
                if check_another:
                    print("!", i, j, x, y, flush=True)
                    break
        else:
            for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                print("?", x, y, flush=True)
                check_another = bool(int(input()))
                if check_another:
                    print("!", i, j, x, y, flush=True)
                    break
        break
else:
    print("?", 0, 9, flush=True)
    check = bool(int(input()))
    if check:
        print("?", 1, 9, flush=True)
        check_another = bool(int(input()))
        if check_another:
            print("!", 0, 9, 1, 9, flush=True)
        else:
            print("!", 0, 8, 0, 9, flush=True)
    else:
        print("?", 8, 0, flush=True)
        check_another = bool(int(input()))
        if check_another:
            print("!", 8, 0, 9, 0)
        else:
            print("!", 9, 0, 9, 1)

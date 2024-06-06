T = int(input())
for i in range(T):
    N = int(input())
    phone = []

    for j in range(N):
        phone.append(input())

    phone = list(sorted(phone))

    for i in range(1, N):
        if phone[i].startswith(phone[i - 1]):
            break
    else:
        print("YES")
        continue
    print("NO")

T = int(input())
for i in range(T):
    N = int(input())
    dp = [False for i in range(7)]
    dp[1] = True

    for j in range(N):
        new_dp = [False for k in range(7)]
        p_1, v_1, p_2, v_2 = input().split()
        v_1, v_2 = int(v_1), int(v_2)

        for k in range(7):
            if not dp[k]:
                continue

            if p_1 == "+":
                new_dp[(k + v_1) % 7] = True
            else:
                new_dp[(k * v_1) % 7] = True

            if p_2 == "+":
                new_dp[(k + v_2) % 7] = True
            else:
                new_dp[(k * v_2) % 7] = True
        dp = new_dp.copy()

    print("LUCKY" if dp[0] else "UNLUCKY")

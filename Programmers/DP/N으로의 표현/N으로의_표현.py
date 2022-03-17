# def findMin(N, number, dp):
#     if N == number:
#         return 1
#     else:
#         min = 2 * number
#         for i in range(1, number):
#             if dp[i] + dp[number - i] < min:
#                 min = dp[i] + dp[number - i]
#                 print(i, ", " , number - i)
#         return min

# def dp(N, number):
#     d = [0, {N}]
#     print(d)
#     d = [0] * (number + 1)
#     if N == number:
#         d[1] = 1
#     else:
#         d[1] = 2
#     for i in range(2, number + 1):
#         d[i] = findMin(N, i, d)
#         print(i , " : " , d[i])
#     return d[number]

def dp(N, number):
    d = [0, {N}]
    for i in range(2, 9):
        d_set = {int(str(N) * i)}
        for j in range(1, i // 2 + 1):
            for x in d[j]:
                for y in d[i - j]:
                    d_set.add(x + y)
                    d_set.add(x - y)
                    d_set.add(y - x)
                    d_set.add(x * y)
                    if x != 0:
                        d_set.add(y // x)
                    if y != 0:
                        d_set.add(x // y)
        if number in d_set:
            # print(d_set)
            return i
        d.append(d_set)
    # print(d)
    return -1

def solution(N, number):
    if N == number:
        return 1
    answer = dp(N, number)
    return answer

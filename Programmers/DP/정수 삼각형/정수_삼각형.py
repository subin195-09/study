# def dp(triangle):
#     triLen = len(triangle)
#     if triLen == 1:
#         return triangle[0][0]
#     if triLen == 2:
#         if triangle[1][0] > triangle[1][1]:
#             return triangle[0][0] + triangle[1][0]
#         else:
#             return triangle[0][0] + triangle[1][1]
#     dp = [0, [(triangle[0][0], 0)]]
#     dp.append([(triangle[0][0] + triangle[1][0],0), (triangle[0][0] + triangle[1][1], 1)])
#     for i in range(3, triLen + 1):
#         tri_dict = []
#         # print(triangle[i - 1])
#         for x in range(len(dp[i - 1])):
#             tri_dict.append((dp[i - 1][x][0] + triangle[i - 1][dp[i - 1][x][1]], dp[i - 1][x][1]))
#             tri_dict.append((dp[i - 1][x][0] + triangle[i - 1][dp[i - 1][x][1] + 1], dp[i - 1][x][1] + 1))
#         dp.append(tri_dict)
#     return (max(dp[triLen])[0])

def dp(triangle):
    size = len(triangle)
    dp = [0, triangle[size - 1]]
    for i in range(size - 2, -1, -1):
        temp_tri = []
        for j in range(len(triangle[i])):
            tri_value = triangle[i][j]
            max_before = max(dp[size - i - 1][j], dp[size - i - 1][j + 1])
            temp_tri.append(tri_value + max_before)
        dp.append(temp_tri)
    # print(dp)
    return dp[size][0]

def solution(triangle):
    answer = dp(triangle)
    return answer

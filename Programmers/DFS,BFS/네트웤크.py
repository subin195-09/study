from collections import Counter
def search(NETlist, target, targetIdx, clan):
    for i in range(len(target[targetIdx])):
        if target[targetIdx][i] == 1:
            NETlist[i] = clan
            target[targetIdx][i] = clan
            search(NETlist, target, i, clan)
def solution(n, computers):
    isNET= [0] * n
    clan = 10;
    for i in range(n):
        search(isNET, computers, i, clan + i);
    return(len(Counter(isNET)))

# answer = []

# def makeCluster(x, y):
#     global answer
#     for a in answer:
#         if a.count(x) > 0 or a.count(y) > 0:
#             a.append(x)
#             a.append(y)
#             return 1
#     return 0

# def dfs(n, computers, x, y):
#     global answer
#     if x == n or y == n:
#         return
#     if y > x:
#         if computers[x][y] == 1:
#             if makeCluster(x, y) == 0:
#                 answer.append([x, y])
#         elif computers[x][y] == 0 and computers[y].count(1) == 1 and answer.count([y]) == 0:
#             answer.append([y])
#     dfs(n, computers, x, y + 1)

# def solution(n, computers):
#     global answer
#     for i in range(0, n + 1):
#         dfs(n, computers, i, 0)
#     result = []
#     for a in answer:
#         result.append(set(a))
#     print(result)
#     return (len(answer))

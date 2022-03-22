# from itertools import combinations

# def solution(orders, course):
#     orders.sort(key=lambda x: len(x), reverse=True)
#     maxLen = len(orders[0])
#     newOrders = []
#     allOrder = []
#     for order in orders:
#         tmpOrder = list(order)
#         newOrders.append(tmpOrder)
#         allOrder += list(tmpOrder)
#     allOrder = set(allOrder)

#     answer = []
#     for i, c in enumerate(course):
#         if maxLen < c:
#             break
#         coms = list(combinations(allOrder, c))
#         answer.append([])
#         maxCount = 0
#         for j, com in enumerate(coms):
#             tmpCount = 0
#             tmpAnswer = []
#             for order in newOrders:
#                 if set(com) & set(order) == set(com):
#                     tmpCount += 1
#             if tmpCount > 1 and tmpCount == maxCount:
#                 answer[i].append(''.join(sorted(com)))
#             elif tmpCount > 1 and tmpCount > maxCount:
#                 answer[i] = []
#                 answer[i].append(''.join(sorted(com)))
#                 maxCount = tmpCount

#     newAnswer = []
#     for a in answer:
#         if a:
#             newAnswer += a
#     return sorted(newAnswer)

from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for i in course:
        temp=[]
        for j in orders:
            combi = combinations(sorted(j),i)
            temp+=combi
        counter = Counter(temp)
        if len(counter) !=0 and max(counter.values())>1:
            answer +=[''.join(x) for x in counter if counter[x]==max(counter.values())]

    return sorted(answer)

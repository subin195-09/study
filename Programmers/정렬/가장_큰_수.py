# import itertools

# # 시간초과
# def solution(numbers):
#     numbers = list(itertools.permutations(numbers, len(numbers)))
#     answer = []
#     for n in numbers:
#         answer.append(''.join(str(x) for x in n))
#     answer = sorted(answer, reverse=True)
#     return answer[0]

from functools import cmp_to_key

def numbers_cmp(x, y):
    if int(x + y) > int(y + x):
        return -1
    else:
        return 1

def solution(numbers):
    numbers = list(str(x) for x in numbers)
    numbers = sorted(numbers, key=cmp_to_key(numbers_cmp))
    numbers = ''.join(numbers)
    return str(int(numbers))

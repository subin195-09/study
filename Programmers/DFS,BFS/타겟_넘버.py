answer = 0

def dfs(numbers, idx, target, result):
    global answer
    if idx == len(numbers):
        if result == target:
            answer += 1
        return
    else:
        dfs(numbers, idx + 1, target, result + numbers[idx])
        dfs(numbers, idx + 1, target, result - numbers[idx])


def solution(numbers, target):
    global answer
    dfs(numbers, 0, target, 0)
    return answer


# from itertools import product
# def solution(numbers, target):
#     l = [(x, -x) for x in numbers]
#     s = list(sum, product(*l))
#     return s.count(target)

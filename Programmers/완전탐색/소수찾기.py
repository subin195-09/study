import itertools

def prime_number(n):
    if n == 0 or n == 1:
        return 0
    if n == 2 or n == 3:
        return 1
    for i in range(1, int(n / 2)):
        if n % (i + 1) == 0:
            return 0
    return 1

def solution(numbers):
    numbers = list(str(numbers))
    # print(numbers)
    all_answer = []
    for i in range(1, len(numbers) + 1):
        all_answer += [int(''.join(i)) for i in list(itertools.permutations(numbers, i))]
    all_answer = set(all_answer)
    answer = 0
    for i in all_answer:
        if prime_number(i):
            answer += 1
    print(answer)
    return answer

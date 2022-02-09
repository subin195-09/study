def solution(brown, yellow):
    all = brown + yellow
    answer = []
    for i in range(1, int(all / 2) + 1):
        if all % i == 0 and (int(all / i) + i) * 2 - 4 == brown:
            answer.append(int(all / i))
            answer.append(i)
            break
    return answer

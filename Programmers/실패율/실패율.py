# 전체 : begin = len(stages) => 실패하면 한명 씩 줄어든다.
# total : n번 스테이지 까지 살아남은 유저 (전체 유저 - (n - 1)번째 스테이지의 탈락한 사람)
# stages : {스테이지, 그 스테이지의 실패한 user의 수} => counter library 활용
# 초반 answer : [스테이지 수, 그 스테이지의 실패율]

# N번째 스테이지 까지 반복문을 돌면서 각 스테이지별 실패율을 구하고, 실패율 대로 정렬을 한다.
# n번 스테이지 실패율 : n번 스테이지의 실패한 사람 / total

from collections import Counter


def solution(N, stages):
    answer = []
    total = len(stages) # 첫 시작은 모든 user가 된다
    stages = dict(Counter(stages))

    for n in range(1, N + 1):
        if n in stages.keys():
            # print(stages[1])
            answer.append([n, stages[n] / total])
            total -= stages[n]
        else:
            answer.append([n, 0])

    answer = [a[0] for a in sorted(answer, key = lambda x :(x[1]), reverse = True)]
    # print(answer)
    return answer

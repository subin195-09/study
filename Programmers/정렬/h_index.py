def solution(citations):
    citations = sorted(citations)
    start = min(citations)
    fin = max(citations)
    i = 0
    answer = start
    for c in range(0, len(citations) + 1):
        tmp_c = len([x for x in citations if x >= c])
        if c <= tmp_c:
            answer = c
        else:
            return answer
    return answer

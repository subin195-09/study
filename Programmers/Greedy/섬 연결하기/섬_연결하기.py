def solution(n, costs):
    answer = 0
    costs.sort(key=lambda x:x[2]) # 비용순으로 정렬
    routes = set([costs[0][0]]) # 어떤 노드들이 갈 수 있는지 저장

    while len(routes) != n:
        for cost in costs:
            if cost[0] in routes and cost[1] in routes:
                continue
            if cost[0] in routes or cost[1] in routes:
                routes.update([cost[0], cost[1]]) # 경로 추가
                answer += cost[2] # 비용 추가
                break

    # print(routes)

    return answer

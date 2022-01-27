def solution(genres, plays):
    al_g = dict()
    al_p = dict()
    for i in range(len(genres)):
        if genres[i] in al_g:
            al_g[genres[i]].append([plays[i], i])
            al_p[genres[i]] += plays[i]
        else:
            al_g[genres[i]] = [[plays[i], i]]
            al_p[genres[i]] = plays[i]
    al_p = sorted(al_p.items(), key=lambda x: x[1], reverse=True)
    answer = []
    for p in al_p:
        al_g[p[0]] = sorted(al_g[p[0]], key=lambda a: (-a[0], a[1]))
        answer.append(al_g[p[0]][0][1])
        if len(al_g[p[0]]) >= 2:
            answer.append(al_g[p[0]][1][1])
    return answer

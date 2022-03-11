answer = []

def dfs(airport, tickets, visited, path):
    global answer
    if len(path) == len(tickets) + 1 and answer == []:
        answer = [p for p in path]
        return
    for i in range(0, len(tickets)):
        if tickets[i][0] == airport and visited[i] == 0:
            visited[i] = 1
            path.append(tickets[i][1])
            dfs(tickets[i][1], tickets, visited, path)
            visited[i] = 0
            path.pop()


def solution(tickets):
    global answer
    tickets = sorted(tickets, key = lambda x : (x[0], x[1]))
    # print(tickets)
    visited = [0] * len(tickets)
    dfs("ICN", tickets, visited, ["ICN"])
    return answer

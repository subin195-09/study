answer = 0
def diffString(a, b):
    stringSize = len(a)
    count = 0
    for i in range(0, stringSize):
        if (a[i] != b[i]):
            count = count + 1
    return count


def dfs(begin, target, words, visited):
    global answer
    if begin == target and answer > len(visited):
        answer = len(visited)
        return ;

    for word in words:
        if word not in visited and diffString(begin, word) == 1:
            visited.append(word)
            dfs(word, target, words, visited)
            visited.remove(word)

def solution(begin, target, words):
    visited = list()
    global answer
    answer = len(words) + 1
    dfs(begin, target, words, visited)
    if answer == len(words) + 1:
        return 0
    else:
        return answer

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

# def diffString(word1, word2):
#     count = 0
#     for i, v in enumerate(word1):
#         if v != word2[i]:
#             count += 1
#     return count

# def dfs(begin, target, words, visited, current):
#     global answer
#     if begin == target:
#         if current < answer:
#             answer = current
#             return
#     for i, word in enumerate(words):
#         if visited[i] == 0 and diffString(begin, word) == 1:
#             visited[i] = 1
#             dfs(word, target, words, visited, current + 1)
#             visited[i] = 0

# def solution(begin, target, words):
#     global answer
#     answer = len(words) + 1

#     if target not in words:
#         return 0

#     visited = [0] * len(words)
#     dfs(begin, target, words, visited, 0)

#     return answer

# 효율성 개선 필요
def checkMin(temp):
    global answer
    if answer == []:
        return 1
    for i in range(10, -1, -1):
        if temp[i] > answer[i]:
            return 1
    return 0

# 어피치가 이겼다면 1, 라이언이 이겼다면 0
def checkWin(info, temp):
    scoreA = 0 # 어피치
    scoreB = 0 # 라이언
    # print(info, temp)
    for i in range(11):
        if info[i] + temp[i] != 0:
            if info[i] >= temp[i]:
                scoreA += 10 - i
            else:
                scoreB += 10 - i
    if scoreA >= scoreB:
        return 0
    else:
        return scoreB - scoreA

# temp : 현재 라이언의 점수판
# count : 라이언의 쏜 활의 갯수
def dfs(n, info, temp, count, pos):
    global answer
    global diff
    if count == n:
        tempDiff = checkWin(info, temp)
        if tempDiff > 0 and tempDiff >= diff:
            if tempDiff > diff:
                diff = tempDiff
                answer = list(temp)
            elif tempDiff == diff and checkMin(temp) == 1:
                answer = list(temp)
        return
    if pos == 11:
        return

    for i in range(11):
        if count + info[i] + 1 <= n:
            temp[i] += info[i] + 1
            dfs(n, info, temp, count + info[i] + 1, i + 1)
            temp[i] -= info[i] + 1

def solution(n, info):
    global answer
    global diff
    diff = 0
    answer = []
    dfs(n, info, [0] * 11, 0, 0)
    if answer == []:
        return [-1]
    return answer

# 참고 코드
# maxScore = 0		# 가장 큰 점수 차이
# maxList = []		# 가장 큰 점수 차이를 낸 배열

# def ryanScore(index, score, n, apeach) :	# dfs 함수
#     if n == 0 : 				# 횟수가 0 이면 calScore() 호출
#         calScore(score, apeach)
#         return

#     if index == 11: return		# 0~10까지의 점수만 존재

#     sc = apeach[index]			# 어피치가 (index)점을 맞힌 횟수
#     for i in range(sc+2):		# 0부터 (index)+1까지 맞히는 경우만 고려
#         if n >= i:			# n보다 크면 안되니까 고려
#             score[index] = i
#             ryanScore(index+1, score, n-i, apeach)
#             score[index] = 0


# def calScore(ryan, apeach):		# 점수 계산 함수
#     global maxScore, maxList
#     rScore = 0	# 라이언 점수
#     aScore = 0	# 어피치 점수

#     for i in range(11):
#         if ryan[i] == 0 and apeach[i] == 0: continue	# 둘다 0이면 패스

#         if ryan[i] > apeach[i] : rScore += (10-i)	# 라이언이 더 많이 맞췄으면 점수획득
#         else : aScore += (10-i)				# 아니면 어피치 점수획득

#     if rScore > aScore :		# 라이언 점수가 더 높을 때만 고려
#         diff = rScore - aScore
#         if diff > maxScore:		# 최대값 갱신
#             maxScore = diff
#             maxList = list(ryan)

#         elif diff == maxScore:			# 최대값이 같을 경우
#             for i in range(11):
#                 if ryan[-i] > maxList[-i]:	# 낮은 점수를 많이 맞은 경우가 선택
#                     maxList = list(ryan)
#                     break
#                 elif ryan[-i] < maxList[-i]:
#                     break


# def solution(n, info):
#     temp = [0 for i in range(11)]
#     ryanScore(0, temp, n, info)		# dfs

#     if len(maxList)==0 : return [-1]
#     else: return maxList

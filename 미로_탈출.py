
dY = [1, -1, 0, 0] # 동 서 남 북
dX = [0, 0, 1, -1]
# answer = 200 * 200 + 1

info = input()
info = info.split()
x = int(info[0])
y = int(info[1])
mapInfo = []
for i in range(x):
	mapInfo.append([int(j) for j in list(input())])

def mapPrint(target):
	for t in target:
		print(t)

def dfs(posX, posY, visited, temp, answer):
	# print(posX, posY, temp)
	# mapPrint(visited)
	if posX == x - 1 and posY == y - 1:
		if temp < answer:
			answer = temp
		return answer
	# print("test : " , temp)
	for i in range(4):
		if posX + dX[i] >= 0 and posX + dX[i] < x and posY + dY[i] >= 0 and posY + dY[i] < y:
			if visited[posX + dX[i]][posY + dY[i]] == 0 and mapInfo[posX + dX[i]][posY + dY[i]] == 1:
				visited[posX + dX[i]][posY + dY[i]] = 1
				answer = dfs(posX + dX[i], posY + dY[i], visited, temp + 1, answer)
				visited[posX + dX[i]][posY + dY[i]] = 0
	return answer

def solution():
	visited = [[0] * y for i in range(x)]
	visited[0][0] = 1
	return(dfs(0, 0, visited, 1, 200 * 200 + 1))

print(solution())

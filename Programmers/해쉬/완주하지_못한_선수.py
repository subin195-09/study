def solution(participant, completion):
	participant.sort()
	completion.sort()
	completion.append('.')
	for i in range(len(participant)):
		if participant[i] != completion[i]:
			return participant[i]


# collection.Counter 연산자 사용
# import collections

# def solution(participant, completion):
#     answer = collections.Counter(participant) - collections.Counter(completion)
#     return list(answer.keys())[0]

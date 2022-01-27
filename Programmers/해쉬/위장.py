def solution(clothes):
	array=dict()
	for i in clothes:
		if i[1] in array:
			array[i[1]].append(i[0])#키가 array에 있을경우 키에 있는 리스트에 값을 넣음
		else:
			array.setdefault(i[1],[i[0]]) #키가 array에 없을경우 키와 [값]를 넣음
	v=[] #종류에 따른 옷의 수량을 파악
	for i in array.values():
		v.append(len(i)+1) #입지 않은 경우 포함
	s = 1
	for i in v: # 옷 종류 중에 하나를 고름
		s *= i
	s -= 1 # 옷을 하나도 않입는 경우는 제외
	return s

# 정답은 맞지만, 효율성 통과 X
# from itertools import combinations
#
# def solution(clothes):
	# dict = {}
	# for c in clothes:
		# dict[c[0]] = c[1]
	# dict_len = len(dict)
	# answer = 0
	# value = dict.values()
	# value_check = len(set(value))
	# if value_check == 1:
		# return dict_len
	# for i in range(dict_len):
		# com_list = list(combinations(value, i + 1))
		# dup = []
		# for j in reversed(range(len(com_list))):
			# if (len(com_list[j]) == len(set(com_list[j]))):
				# answer += 1
	# return answer

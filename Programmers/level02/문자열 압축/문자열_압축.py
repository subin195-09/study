# checker의 최대 길이 : len(s) // 2

def solution(s):
    if len(set(s)) == 1:
        if len(s) != 1:
            return len(str(len(s))) + 1
        else:
            return 1

    answer = []
    for check_len in range(1, len(s) // 2 + 1):
        checker = s[:check_len]
        count = 0
        temp_answer = ""
        for i in range(0, len(s), check_len):
            # print(i, " : ", s[i:i + check_len], ", check : ", checker)
            if s[i:i + check_len] == checker:
                count += 1
            else:
                if count == 1:
                    temp_answer += checker
                else:
                    temp_answer += str(count) + checker
                count = 1
                checker = s[i:i + check_len]
        if count == 1:
            temp_answer += checker
        else:
            temp_answer += str(count) + checker
        answer.append(len(temp_answer))
    print(answer)
    return min(answer)

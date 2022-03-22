def solution(record):
    answer = []
    user = dict()
    chat = []
    for r in record:
        r = r.split()
        if len(r) == 3:
            user[r[1]] = r[2]
        if r[0] == 'Enter':
            chat.append((r[1], '님이 들어왔습니다.'))
        elif r[0] == 'Leave':
            chat.append((r[1], '님이 나갔습니다.'))
    # print(user)
    # print(chat)
    answer = []
    for c in chat:
        answer.append(user[c[0]] + c[1])

    return answer

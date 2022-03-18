def solution(n, lost, reserve):
    student = [1] * n
    for l in lost:
        student[l - 1] -= 1
    for r in reserve:
        student[r - 1] += 1
    if student[0] == 0 and student[1] == 2:
        student[0] = 1
        student[1] = 2
    if student[len(student) - 1] == 0 and student[len(student) - 2] == 2:
        student[len(student) - 1] == 1
        student[len(student) - 2] == 1
    for i in range(1, len(student) - 1):
        if student[i] == 0:
            if student[i - 1] == 2:
                student[i] = 1
                student[i - 1] = 1
            elif student[i + 1] == 2:
                student[i] = 1
                student[i + 1] = 1
    answer = 0
    for s in student:
        if s != 0:
            answer += 1
    return answer

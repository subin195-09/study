def solution(answers):
    num_one = [1, 2, 3, 4, 5]
    num_two = [2, 1, 2, 3, 2, 4, 2, 5]
    num_three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    one_len = len(num_one)
    two_len = len(num_two)
    three_len = len(num_three)
    answer = [0, 0, 0]
    for i in range(0, len(answers)):
        if answers[i] == num_one[i % one_len]:
            answer[0] += 1
        if answers[i] == num_two[i % two_len]:
            answer[1] += 1
        if answers[i] == num_three[i % three_len]:
            answer[2] += 1
    answer = [i + 1 for i, value in enumerate(answer) if value == max(answer)]
    return answer

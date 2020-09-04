#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 스택의 원리를 이용
char stack[30];
int stack_index = 0;

void push(char skill)
{
    stack[stack_index] = skill;
    stack_index++;
}

char top()
{
    return stack[stack_index - 1];
}

void reset()
{
    stack_index = 0;
}

int check_skill(char *skill, char tree_char)
{
    int i = 0;
    while (skill[i])
    {
        if (tree_char == skill[i])
        {
            if (i == 0)
                push(tree_char);
            else if (top() == skill[i -1])
                push(tree_char);
            else
                return 0;
        }
        i++;
    }
    return 1;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;
    int flag = 1;
    int j = 0;
    
    for (int i = 0; i < skill_trees_len; i++)
    {
        j = 0;
        flag = 1;
        reset();
        while (skill_trees[i][j])
        {
            if (!check_skill(skill, skill_trees[i][j]))
                flag = 0;
            j++;
        }
        if (flag)
            answer++;
    }
    return answer;
}
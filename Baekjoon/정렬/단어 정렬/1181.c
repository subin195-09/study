#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char word[51];
    int len;
} WORD;

int compare(const void *a, const void *b)
{
    WORD word1 = *(WORD *)a;
    WORD word2 = *(WORD *)b;

    if (word1.len < word2.len)
        return -1;
    else if (word1.len > word2.len)
        return 1;
    else
    {
        if(strcmp(word1.word, word2.word) < 0)
            return -1;
        else if(strcmp(word1.word, word2.word) > 0)
            return 1;
        else
            return 0;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    WORD w[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", w[i].word);
        w[i].len =  strlen(w[i].word);
    }
    
    qsort(w, n, sizeof(WORD), compare);

    printf("%s\n", w[0].word);
    for(int i = 1; i < n; i++)
    {
        if (strcmp(w[i - 1].word, w[i].word) != 0)
            printf("%s\n", w[i].word);
    }
}
#include <stdio.h>
#include <string.h>

int CountSpaces(char s[])
{
    int count = 0;

    for (int i = 0; i < 100; i++)
    {
        if (s[i] == NULL)
            break;
        if (s[i] == ' ')
            count++;
    }

    return count;
}

int main()
{
    char str[100] = { 0 };
    fgets(str, 100, stdin);
    printf("#words=%d\n", CountSpaces(str) + 1);

    return 0;
}
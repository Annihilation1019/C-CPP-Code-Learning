#include <stdio.h>
#include <string.h>
int main()
{
    char name[6] = {'h', 'e', 'l', 'l', 'o'};
    char str[] = {'c', 'a', 't', '\0'}; // 尤其注意空字符的存在，十分重要
    char stri[] = "world";
    printf("%d\n%d\n%d\n", sizeof(name), sizeof(str), sizeof(stri));
    printf("%s\n%s\n%s\n", name, str, stri);
    return 0;
}
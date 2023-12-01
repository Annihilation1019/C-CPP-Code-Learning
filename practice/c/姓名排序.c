// qsort()快速排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10
struct names
{
    char first[LEN];
    char last[LEN];
};
int cmp(const void *p1, const void *p2);
int main()
{
    struct names name[5] = {{"Jack", "Smith"}, {"Charlie", "Brown"}, {"Carl", "Trump"}, {"Christine", "Best"}, {"Andy", "White"}};
    qsort(name, 5, sizeof(struct names), cmp);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%s %s\n", name[i].first, name[i].last);
    }
}
int cmp(const void *p1, const void *p2)
{
    const struct names *s1 = (struct names *)p1;
    const struct names *s2 = (struct names *)p2;
    int res;
    res = strncmp(s1->last, s2->last, 1);
    if (res != 0)
    {
        return res;
    }
    else
    {
        return strcmp(s1->first, s2->first);
    }
}
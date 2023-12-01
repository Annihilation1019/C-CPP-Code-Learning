#include <stdio.h>
typedef enum month
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
} A,
    *pmonth;
int main()
{
    A m = Oct;
    pmonth p = &m;
    printf("%d\n%d\n%d", m, *p, Jun);
    return 0;
}

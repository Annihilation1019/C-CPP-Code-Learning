#include<stdio.h>
int main()
{
    float a = 0xa.1fp10f;//表示的值是(10+1/16+15/256)*2^10
    printf("%f\n", a);
    printf("%a\n", a);
    printf("%A\n", a);
    printf("%e\n", a);
    printf("%E\n", a);
    return 0;
}
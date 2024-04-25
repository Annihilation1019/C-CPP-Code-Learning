#include <stdio.h>
int main()
{
    int a = 12;
    float b = 3.1415f; // 编译器默认为double类型，所以要加f，否则会有警告，但是不影响运行，但是会影响精度，因为double类型的精度比float高，所以会有精度损失，所以要加f，表示float类型，这样就不会有精度损失了
    char c = 'A';
    printf("%d\n", a);
    printf("0%o\n", a);
    printf("0x%x\n", a);
    printf("%-7.2e,yes", b);
    printf("%c\n", c);
    c = getchar();
    return 0;
}
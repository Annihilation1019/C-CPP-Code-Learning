// 这就是多个不同的case，想执行同一条语句的做法
#include <stdio.h>
int main()
{ // switch结构会判断从哪个case开始执行，然后接着后面所有的case后面的语句都执行完
    int day = 0;
    do
    {
        printf("请输入：>");
        scanf("%d", &day);
        switch (day)
        { // switch()和case()后面必须是整型的
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("周内\n");
            break;
        case 6:
        case 7:
            printf("周末\n");
            break;
        default: // default语句的位置是非常自由的
            printf("输入错误，请重新输入\n");
            break;
        case 0:
            printf("退出\n");
            break;
        }
    } while (day);
    return 0;
}

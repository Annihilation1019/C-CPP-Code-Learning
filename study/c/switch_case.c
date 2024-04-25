#include <stdio.h>
int main()
{ // switch结构会判断从哪个case开始执行，然后接着后面所有的case后面的语句都执行完
    int day = 0;
    do
    {
        printf("请输入：>");
        scanf("%d", &day);
        switch (day) // switch在圆括号中的表达式只能是整型或者字符型，不能是浮点型，也不能是字符串，也不能是表达式，case后面的值必须是常量，不能是变量，也不能是表达式，case后面的值不能重复。
        {
        case 1:
            printf("星期一\n");
            break; // 跳出分支
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        case 7:
            printf("星期七\n");
            break;
        case 0:
            printf("退出\n");
            break;
        default: // default语句的位置是非常自由的
            printf("输入错误，请重新输入\n");
            break;
        }
    } while (day);
    return 0;
}

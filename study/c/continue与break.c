#include <stdio.h>
int main(void)
{
    int val; // variable的缩写, “变量”的意思
    printf("请输入您想去的楼层:");
    while (1)
    {
        scanf("%d", &val);
        switch (val)
        {
        case 1:
            printf("1层开!\n");
            break; // 跳出switch
        case 2:
            printf("2层开!\n");
            break; // 跳出switch
        case 3:
            printf("3层开!\n");
            break; // 跳出switch
        default:
            printf("该层不存在, 请重新输入:");
            continue; // 结束本次while循环
        }
        break; // 跳出while
    }
    return 0;
}
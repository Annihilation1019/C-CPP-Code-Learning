/*while (getchar!='\n')
{
    continue;//跳过剩余的输入行,继续读取下一行的输入,这样就可以清空输入行了
}

输入验证：
while(scanf("%d",&n)!=1)//scanf()函数返回成功读取的项目数,如果读取的不是一个整数,则返回0
{
    while(getchar()!='\n')//输入实际是字符流
    {
        continue;//处理错误的输入
    }
    printf("Please enter an integer:");
}

处理非整数输入：
while(scanf("%d",&n)!=1)//如果读取失败,则执行循环体
{
    scanf("%*s");//跳过非整数输入
    printf("Please enter an integer:");
}

检查非数值输入和超出范围的数据
while(scanf("%d",&n)!=1||(n<0||n>10))//如果读取失败,或者读取的数值超出范围,则执行循环体
{//从左到右对表达式求值,如果第一个条件为真,则不再计算第二个条件，如果求值结果为假,则不再计算后面的条件
    scanf("%*s");
    printf("Please enter an integer between 0 and 10:");
}
*/
// 菜单程序示例(c primer plus 6th edition P.238)
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(void)
{
    int choice;
    void count(void);

    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            printf("Buy low,sell high.\n");
            break;
        case 'b':
            putchar('\a');
            break;
        case 'c':
            count();
            break;
        default:
            printf("Program error!\n");
            break;
        }
    }
    printf("Bye.\n");

    return 0;
}

void count(void)
{
    int n, i;
    printf("Count how far?Enter an integer:\n");
    n = get_int();
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
    while (getchar() != '\n')
    {
        continue;
    }
}

char get_choice(void)
{
    int ch;

    printf("Enter the letter of your choice:\n");
    printf("a.advice          b.bell\n");
    printf("c.count           q.quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a,b,c or q.\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
    {
        continue;
    }

    return ch;
}

int get_int(void)
{
    int input;
    char ch;

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25,-178,or3:");
    }

    return input;
}
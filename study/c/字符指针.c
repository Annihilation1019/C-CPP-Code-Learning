#include<stdio.h>
    int main()
    {
        char arr[] = "abcdef"; // 字符串存入arr数组里面
        char *pc = arr;        // pc字符指针存放数组名，即首元素地址。
        printf("%s\n", arr);
        printf("%s\n", pc);
        return 0;
    } // 将字符串赋值给一个字符指针变量p，不是把字符串的内容赋值给p，而是把字符串首字符的地址赋给了p。进一步说明字符数组在内存中是连续的
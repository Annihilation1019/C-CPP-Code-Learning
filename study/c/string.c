#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H "Hello,how are you?"
void print(char **s, int n);
int main()
{
    char g[50] = "Hello,"
                 "how "
                 "are "
                 "you"
                 "?"; // 字符串字面量可以拼接，等同于char greeting[50]="Hello,how are you?";
    printf("%s\n", g);
    // 用双引号括起来的内容被视为指向该字符串储存位置的指针，类似于把数组名作为指向该数组位置的指针
    printf("%s\n%p\n%c\n", "Hello,", "how ", *"are "); // *greeting == greeting[0]
    const char *p = H;                                 // 字符串字面量是常量，不能修改，除非把字符串字面量拷贝给一个数组，但可以修改指向它们的指针
    //*p = 'A';//通常会导致程序崩溃！编译器可以使用内存中的一个副本来表示所有完全相同的字符串字面量，如果允许修改，那么将影响所有使用该字符串的代码

    char *p1 = H;
    printf("%p\n%p\n%p\n%p\n", g, p1, &p1, H);
    // p1的值和H的地址相同，而和g地址不同，因为字符串储存在静态存储区，程序在开始运行时才会为该数组分配内存，此时才将字符串拷贝到数组中，字符串有两个副本：静态内存中的字面量原始副本和数组中的副本

    // 字符串数组
    char *p2[5] = {"Hello", "how", "are", "you", "?"};   // p2是一个指针数组，每个元素都是一个指向char的指针，占用40个字节
    char a[5][10] = {"Hello", "how", "are", "you", "?"}; // a是一个二维数组，每个元素都是一个含有10个char元素的数组，占用50个字节，内存分配使用率较低
    printf("%d\n%d\n", sizeof(p2), sizeof(a));           // 更推荐第一种形式，因为指针数组的内存分配使用率较高，但第一种形式不可修改字符串，第二种形式可以修改字符串
    print(p2, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", a[i]);
    }

    // 字符串输入(一定要先分配空间)
    char str[15];
    /*puts("Enter a string:"); // warning: call to 'gets' declared with attribute warning: Using gets() is always unsafe - use fgets() instead [-Werror,-Wdeprecated-declarations]
    gets(str); // 读取一行字符串，包括空格，遇到换行符停止读取，换行符不储存
    puts(str); // 输出字符串，自动换行
    puts("Done!");*/

    // 字符串输入(推荐)
    fgets(str, 15, stdin); // 读取一行字符串，包括空格，遇到换行符停止读取，换行符储存
    fputs(str, stdout);    // 输出字符串，不自动换行
    puts("\n");
    gets_s(str, 15); // 读取一行字符串，包括空格，遇到换行符停止读取(换行符也占一个字符)，换行符不储存。若读到最大字符数时没有读到换行符，执行以下操作：把目标数组中的首字符设置为空字符，读取并丢弃随后的输入直至读到换行符或文件结尾，然后返回空指针
    puts(str);       // 输出字符串，自动换行

    // 字符串函数(string.h)
    char *arr1 = "Hello, world!";
    char *arr2 = "I'm fine, thank you!";
    char arr3[40] = "Hello, world!";
    char arr4[40];
    printf("%d\n", strlen(arr1));           // 返回字符串长度，不包括空字符
    printf("%s\n", strcat(arr3, arr2));     // 把第二个字符串拼接到第一个字符串后面，返回第一个字符串的地址
    printf("%s\n", strncat(arr3, arr2, 2)); // 把第二个字符串的前n个字符拼接到第一个字符串后面，返回第一个字符串的地址
    printf("%d\n", strcmp(arr1, arr2));     // 比较两个字符串，相等返回0，第一个字符串大返回正数，第二个字符串大返回负数(只会比较第一个空字符前面的部分，可以用来比较储存在不同大小数组中的字符串)
    printf("%d\n", strncmp(arr1, arr2, 2)); // 比较两个字符串的前n个字符，相等返回0，第一个字符串大返回正数，第二个字符串大返回负数
    printf("%s\n", strcpy(arr3, arr2));     // 把第二个字符串拷贝到第一个字符串中，返回第一个字符串的地址
    printf("%s\n", strncpy(arr4, arr2, 2)); // 把第二个字符串的前n个字符拷贝到第一个字符串中，返回第一个字符串的地址(第一个参数不必指向数组的开始，如strncpy(arr4+2,arr2,2))
    char st[50];
    int c = 10, c1;
    float d = 3.14, d1;
    sprintf(st, "c = %d, d = %.2f", c, d);        // 把格式化的数据写入字符串，返回写入字符的个数
    sscanf(st, "c = %d, d = %f", &c1, &d1);       // 从字符串中读取格式化的数据，返回成功读取的数据个数(第二个参数为格式化字符串，第三个参数为要读取的数据的地址,常用于解析字符串)
    printf("%s\n", st);                           // 输出 "c = 10, d = 3.14"
    printf("%d %.2f\n", c1, d1);                  // 输出 "10 3"
    snprintf(st, 50, "c = %d, d = %.2f", c, d);   // 把格式化的数据写入字符串，返回写入字符的个数(第二个参数为最大写入字符数，防止溢出)
    printf("%d\n", strchr(arr1, 'l') ? 1 : 0);    // 在字符串中查找字符，返回第一次出现该字符的地址，若没有找到返回空指针
    printf("%d\n", strrchr(arr1, 'l') ? 1 : 0);   // 在字符串中查找字符，返回最后一次出现该字符的地址，若没有找到返回空指针
    printf("%d\n", strstr(arr1, "llo") ? 1 : 0);  // 在字符串中查找字符串，返回第一次出现该字符串的地址，若没有找到返回空指针
    printf("%d\n", strpbrk(arr1, "zlk") ? 1 : 0); // 在字符串中查找字符串中任意字符第一次出现的位置，返回第一次出现该字符的地址，若没有找到返回空指针

    // 字符串转换函数(stdlib.h)
    char *arr5 = "123";
    char *arr6 = "123.456";
    printf("%d\n", atoi(arr5));                // 把字符串转换为整数，458regular只会转换为458
    printf("%f\n", atof(arr6));                // 把字符串转换为浮点数
    printf("%ld\n", atol(arr5));               // 把字符串转换为长整数
    printf("%lld\n", atoll(arr5));             // 把字符串转换为长长整数
    printf("%d\n", strtol(arr5, NULL, 10));    // 把字符串转换为长整数，第二个参数为指向第一个非空白字符的指针，第三个参数为进制，返回转换后的长整数(它的第三个参数base用于指定输入字符串的数制(2-36)，但输出总是以十进制的形式给出)
    printf("%d", strtof(arr6, NULL));          // 把字符串转换为浮点数，第二个参数为指向第一个非空白字符的指针，返回转换后的浮点数
    printf("%f\n", strtod(arr6, NULL));        // 把字符串转换为浮点数，第二个参数为指向第一个非空白字符的指针，返回转换后的浮点数
    printf("%ld\n", strtoul(arr5, NULL, 10));  // 把字符串转换为无符号长整数，第二个参数为指向第一个非空白字符的指针，第三个参数为进制，返回转换后的无符号长整数
    printf("%lld\n", strtoll(arr5, NULL, 10)); // 把字符串转换为无符号长长整数，第二个参数为指向第一个非空白字符的指针，第三个参数为进制，返回转换后的无符号长长整数

    return 0;
}

void print(char **s, int n)
{
    for (int i = 0; i < n; i++, s++)
    {
        printf("%s", *s);
    }
    printf("\n");
}
// 数组表示法比指针表示法更加易懂，但指针表示法更加灵活，可以处理多维数组
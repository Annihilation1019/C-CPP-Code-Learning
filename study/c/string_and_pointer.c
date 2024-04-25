#include <stdio.h>
int main()
{ // string是字符串名，又是字符串的首地址
    char string[] = "I love China!";
    printf("%s  ", string);  // 源字符串   I love China!
    printf("%d  ", &string); // 字符串的首地址  	6422034
    printf("%c  ", *string); // 字符串首地址的内容	 I

    printf("%d  ", string + 7);    // 字符一个占一个字节，这里的string就代表首地址，加7就相当于往后移动了七个字节，到了C的地址的位置   6487575
    printf("%c  ", *(string + 7)); // 打印下该地址的字符是啥  C
    printf("%s  ", string + 7);    // 从C开始往后打印    China!
    return 0;
}
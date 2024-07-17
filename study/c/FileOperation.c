#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ch;
    FILE *fp = fopen("text.txt", "w+");
    if (fp == NULL) // 判断文件是否打开成功
    {
        printf("open file error!\n");
        exit(0);
    }
    while ((ch = getchar()) != EOF)
    {
        fputc(ch, fp); // 将字符写入文件
    }
    fclose(fp); // 关闭文件

    fp = fopen("text.txt", "a+");
    if (fp == NULL) // 判断文件是否打开成功
    {
        printf("open file error!\n");
        exit(0);
    }
    fprintf(fp, "hello world\n");
    rewind(fp); // 将文件指针指向文件开头
    int year, month, day;
    fscanf(fp, "%d-%d-%d", &year, &month, &day);
    printf("%d-%d-%d\n", year, month, day);
    fclose(fp); // 关闭文件

    fp = fopen("text.txt", "a+");
    if (fp == NULL) // 判断文件是否打开成功
    {
        printf("open file error!\n");
        exit(0);
    }
    rewind(fp); // 将文件指针指向文件开头
    char str[100];
    fgets(str, 10, fp);
    fputs(str, stdout);
    fclose(fp); // 关闭文件

    // 随机访问
    fp = fopen("text.txt", "a+");
    if (fp == NULL) // 判断文件是否打开成功
    {
        printf("open file error!\n");
        exit(0);
    }
    fseek(fp, -13L, SEEK_END); // 将文件指针指向文件末尾,向前移动13个字节
    long pos = ftell(fp);      // 获取文件指针的位置，返回的是从文件开始到当前文件指针位置的字节数
    fgets(str, 12, fp);
    fputs(str, stdout);
    printf("文件指针的位置是%ld\n", pos);
    fclose(fp); // 关闭文件
    return 0;
}
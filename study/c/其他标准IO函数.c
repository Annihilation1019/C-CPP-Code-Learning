#include <stdio.h>
#include <unistd.h>
int main()
{
    FILE *fp = fopen("text.txt", "w+");
    if (fp == NULL) // 判断文件是否打开成功
    {
        printf("open file error!\n");
        return 0;
    }

    // int unggetc(int ch, FILE *fp); 将字符ch退回到输入流
    fputs("hello world\n", fp);
    rewind(fp); // 将文件指针指向文件开头
    printf("读取一个字符：%c\n", fgetc(fp));
    ungetc('a', fp); // 将字符a退回到输入流
    printf("再读取一个字符：%c\n", fgetc(fp));
    fclose(fp); // 关闭文件

    // int fflush(FILE *fp); 刷新缓冲区
    int a[5] = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
        fflush(stdout); // 刷新缓冲区，缓冲区中的数字一个一个跳出来
        sleep(1);
    }
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
        // 不刷新缓冲区，可能会将5个数字字符输出到了缓冲区中，然后一起显示出来
    }

    // int setvbuf(FILE *fp, char *buf, int mode, size_t size); 设置缓冲区
    char buf[BUFSIZ];                          // 创建了一个BUFSIZ大小的缓冲区
    setvbuf(stdout, buf, _IOFBF, sizeof(buf)); // 第一个参数是文件指针，表示要设置缓冲策略的流，第二个参数是缓冲区(如果NULL会自动分配一个缓冲区)，第三个参数是缓冲区的类型，第四个参数是缓冲区的大小
    /*_IOFBF：全缓冲。在这种模式下，只有当缓冲区满或者你显式调用fflush或fclose时，才会进行实际的I/O操作。
      _IOLBF：行缓冲。在这种模式下，每次遇到换行符或者你显式调用fflush或fclose，或者缓冲区满时，才会进行实际的I/O操作。
      _IONBF：无缓冲。在这种模式下，每次调用I/O函数，都会立即进行实际的I/O操作。*/
    printf("Hello, world!");
    fflush(stdout); // 刷新缓冲区，将"Hello, world!"立即输出

    // size_t fwrite() 把二进制数据写入文件
    fp = fopen("text.txt", "wb+");
    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return -1;
    }
    int c[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int d[10];
    fwrite(c, sizeof(int), 10, fp); // 将c中的数据写入文件

    // 移动文件指针到文件开始，以便读取数据
    fseek(fp, 0, SEEK_SET);

    fread(d, sizeof(int), 11, fp); // 将文件中的数据读入d中
    if (feof(fp))                  // 判断是否到达文件末尾，feof只有在尝试从文件尾后面读取数据之后才会返回非零值，仅仅到达文件尾是不够的。
    {
        printf("End of file reached.\n");
    }
    else
    {
        printf("Something went wrong.\n");
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", d[i]);
        fflush(stdout);
    }
    printf("\n");
    if (ferror(fp)) // 判断是否发生了错误
    {
        printf("An error occurred.\n");
        fflush(stdout);
    }
    else
    {
        printf("No error occurred.\n");
        fflush(stdout);
    }
    fclose(fp);
    return 0;
}

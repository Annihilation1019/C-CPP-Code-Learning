#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 41
#define MAXAUTL 31
#define LEN 20
// 结构名不是结构的地址，要用&取地址
struct book // 结构模板：标记是book,并未创建实际数据对象(还未分配空间)
{           // 结构成员列表
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}; // 可以放在所有函数外部或函数内部，决定其是否有块作用域;

// 嵌套结构
struct names
{
    char first[LEN];
    char last[LEN];
};
struct pnames // 结构本身只储存了两个地址，用来在程序中管理那些已分配和在别处分配的字符串
{
    char *first;
    char *last;
};
struct guy
{
    struct names handle; // 嵌套结构
    char favfood[LEN];
    char job[LEN];
    float income;
};

// 伸缩型数组成员(C99)
struct flex
{
    int count;
    double average;
    double scores[]; // 伸缩型数组成员必须是结构的最后一个成员，并没有给这个数组预留空间，只是一个占位符
};

// 匿名结构(C11)
struct person
{
    int id;
    struct
    {
        char first[LEN];
        char last[LEN];
    };
};

float tax(float, float);
float taxp(const struct guy *money);
void show(struct book library);
struct book copy2(struct book library);
double sum(const struct book *library); // 括号内等效于const struct book library[]
int main()
{
    // 这里把library声明为一个book类型(使用book结构布局)的变量，编译器使用book模板为该变量分配空间(struct book相当于int,float,char等类型)
    struct book library = {"C Programming", "", 0.0}; // 初始化结构变量，初始化列表中的值必须按照声明的顺序给出
    /*结构的初始化器：
      struct book library = {.title = "", .value = 9.99};
      只初始化一部分，其他成员自动初始化为0(或空字符)*/
    library.value = 9.99f; // 使用结构成员运算符(.)访问结构成员，本质上相当于book结构的下标
    printf("%s %.2f\n", library.title, library.value);
    printf("结构体book的大小是%zd字节\n", sizeof(struct book)); // 计算结构大小

    // 结构数组
    struct book librarys[3] = {
        {"C Programming", "Tom", 9.99},
        {"C++ Programming", "Jerry", 19.99},
        {"Java Programming", "Jack", 29.99}};
    printf("%s %.2f\n", librarys[0].title, librarys[1].value);
    /*librarys 一个book结构的数组
      librarys[2] 一个数组元素，该元素是book结构
      librarys[2].title 一个char数组(librarys[2]中的title成员)
      librarys[2].title[4] 成员的一个字符*/

    // 嵌套结构
    struct guy fellow[2] = {
        {{"Tom", "Jerry"}, "pizza", "teacher", 10000.0},
        {{"Jack", "Rose"}, "hamburger", "student", 1000.0}};
    printf("%s %s\n", fellow[0].handle.first, fellow[0].handle.last);
    printf("%s %s\n", fellow[1].favfood, fellow[1].job);

    // 结构指针
    struct guy *him;                                        // 声明一个指向结构的指针
    him = &fellow[0];                                       // 指向结构数组的第一个元素
    printf("%s %s\n", him->handle.first, him->handle.last); // 使用指针访问结构成员，使用->运算符，相当于(*him).handle.first

    // 结构和函数
    printf("税金是%.2f\n", tax((him + 1)->income, 0.2));
    printf("税金是%.2f\n", taxp(him));
    show(librarys[0]);

    // 其他结构特性
    //  1.结构赋值
    struct book copy;
    copy = library;
    printf("%s %.2f\n", copy.title, copy.value);
    // 2.传递并返回结构
    struct book copyx = copy2(library);
    printf("%s %.2f\n", copyx.title, copyx.value);

    // 字符数组和字符指针
    struct names veep = {"Tommy", "Jerry"};
    struct pnames vp = {"Jack", "Rose"};
    printf("结构的大小:veep占%zd字节，vp占%zd字节\n", sizeof(struct names), sizeof(struct pnames));

    // 复合字面量和结构(C99),可以在复合字面量中使用初始化器
    struct book co;
    co = copy2((struct book){"Tom", "Jerry"});
    printf("%p\n", "Tom");

    // 伸缩型数组成员(C99)
    struct flex *pf1;
    printf("分配前大小是%zd\n", sizeof(struct flex));
    pf1 = (struct flex *)malloc(sizeof(struct flex) + 10 * sizeof(double)); // 为伸缩型数组成员分配空间
    printf("分配后大小是%zd\n", sizeof(struct flex) + 5 * sizeof(double));
    pf1->count = 10;
    for (int i = 0; i < 10; i++)
    {
        pf1->scores[i] = 20.0 - i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", pf1->scores[i]);
    }
    printf("\n");
    free(pf1);

    // 匿名结构
    struct person president = {1, {"Tom", "Jerry"}};
    printf("%s %s\n", president.first, president.last); // 匿名结构成员的访问，简化了访问过程

    // 结构数组的函数
    struct book library1[2] = {
        {"C Programming", "Tom", 9.99},
        {"C++ Programming", "Jerry", 19.99}};
    printf("总价值是%.2f\n", sum(library1));

    // 把结构内容保存到文件中
    FILE *fp;
    fp = fopen("book.dat", "wb"); // 以二进制写入模式打开文件
    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return -1;
    }
    fwrite(library1, sizeof(struct book), 2, fp); // 将library1中的数据写入文件
    fclose(fp);                                   // 关闭文件

    // 从文件中读取结构内容
    struct book library2[2];
    fp = fopen("book.dat", "rb"); // 以二进制读取模式打开文件
    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return -1;
    }
    fread(library2, sizeof(struct book), 2, fp); // 将文件中的数据读入library2中
    fclose(fp);                                  // 关闭文件
    for (int i = 0; i < 2; i++)
    {
        printf("%s %s %.2f\n", library2[i].title, library2[i].author, library2[i].value);
    }

    return 0;
}

// 传递结构成员
float tax(float income, float rate)
{
    return income * rate;
}

// 传递结构地址
float taxp(const struct guy *money)
{
    return money->income * 0.2;
}

// 传递结构，效率低，兼容性低且没必要
void show(struct book library)
{
    printf("%s %.2f\n", library.title, library.value);
}

// 返回结构
struct book copy2(struct book library)
{
    return library;
}

// 结构数组的函数
double sum(const struct book *library)
{
    double total = 0;
    for (int i = 0; i < 2; i++)
    {
        total += library[i].value;
    }
    return total;
}
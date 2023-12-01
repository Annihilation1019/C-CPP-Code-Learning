#include <stdio.h>
/*与#define的不同点：
  1.typedef创建的符号名受限于类型，不能用于值
  2.typedef由编译器解释，不是预处理器
  3.受限范围内比#define灵活*/

typedef int integer;
typedef char *string; // 替换了类型名称
#define char *STRING; // 仅仅替换宏定义(替换代码中的某些部分)
/*区别：string name,sign相当于char *name,*sign，
        STRING name,sign相当于char *name,sign*/
typedef struct NUM // 此时标签可以省略
{
  integer a;
  integer b;
} DATA, *PTRDATA; // 此时DATA等同于struct NUM，*PTRDATA等同于struct NUM *。

typedef int arr5[5];      // arr5是一个数组类型，包含5个int类型的元素
typedef arr5 *ptr5;       // ptr5是一个指针类型，指向一个包含5个int类型元素的数组
typedef ptr5 arrptr5[10]; // arrptr5是一个数组类型，包含10个ptr5类型的元素
//(*arrptr5[10])[5]
int main()
{
  DATA data;     // 定义结构体变量
  PTRDATA pdata; // 定义结构体指针,注意不要多写*
  pdata = &data; // 结构体指针指向结构体变量
  data.a = 100;
  data.b = 500;
  printf("a=%d\nb=%d\n", data.a, data.b);
  printf("a=%d\nb=%d\n", pdata->a, pdata->b);
  return 0;
}
#include <stdio.h>
#define MONTHS 12
void print_array(int arr[], int sz);
void print_array2(int arr[][10], int sz);

int main()
{ // 传统的语法，只初始化arr[5]
    int arr[6] = {0, 0, 0, 0, 0, 6};

    // C99新增的语法，初始化arr[3]和arr[5]
    int arr1[6] = {[3] = 12, [5] = 6};
    print_array(arr, 6);

    // C99新增的语法，初始化arr[1]到arr[3]
    int arr2[6] = {[1 ... 3] = 12};
    print_array(arr2, 6);

    // 如果指定初始化器后面有更多的值，那么后面的值将被用于初始化指定元素之后的元素；如果再次初始化指定的元素，那么最后的初始化将会取代之前的初始化
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    print_array(days, MONTHS);

    // 未指定元素大小，编译器会根据初始化器中的值来计算元素个数
    int stuff[] = {1, [6] = 3, 7, 8, [11] = 9};
    print_array(stuff, sizeof(stuff) / sizeof(stuff[0]));

    // 对二维数组
    int arr3[10][10] = {
        [9] = 1, 2, 3,                 // 初始化arr3[9][0],arr3[9][1],arr3[9][2],注:仅该行起始处可以加大括号
        [2][3] = 2,                    // 初始化arr3[2][3]
        [1 ... 5] = 3,                 // 初始化arr3[1][0]到arr3[5][0]
        [1 ... 5][2] = 4,              // 初始化arr3[1][2]到arr3[5][2]
        [2 ... 4][7 ... 9] = 5,        // 初始化arr3[2][7]到arr3[4][9]
        [8] = {[1 ... 3] = 6, [9] = 7} // 初始化arr3[8][1]到arr3[8][3]和arr3[8][9],这里的[9]是指第二维的下标,[8]相当于是二维数组里的第9个一维数组
    };                                 // 初始化器后面直接添加元素(不在大括号内)等同于把元素以一维数组形式依次向后排列,大括号内元素过多会越界,越界元素不会再向后排列,也不影响其他行元素初始化
    printf("\n");
    print_array2(arr3, 10);
    return 0;
}
void print_array(int arr[], int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void print_array2(int arr[][10], int sz) /*多维数组在内存中是按照行优先的顺序储存的。也就是说，二维数组中的每一行都是一个连续的内存块，而多维数组中的每个元素都是一个单独的内存块。因此，编译器需要知道每一行的大小，才能够正确地计算每个元素在内存中的地址。若第一维大小未知，则无法分配每一行第一元素的首地址*/
{
    for (size_t i = 0; i < sz; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
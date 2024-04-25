// 前置条件：1.有序数组 2.数组元素不重复 3.一次查找一个元素
// 对于n个元素，查找次数最多为log_2 n（一次排除一半的元素）
// 例题：输入一串有序数组，查找某个元素是否存在，存在则返回下标，不存在则返回-1
// 时间复杂度O(log_2 n) 空间复杂度O(1)
#include <stdio.h>
#include <stdlib.h>
int binarysearch(int size, int target, int *a);
void input_arr(int len, int *a);
void if_malloc(int *a);
void input_check(int *val);

int main()
{
    int len, target;

    input_check(&len);
    scanf("%d", &target);
    int *a = (int *)malloc(len * sizeof(int));
    if_malloc(a);
    printf("请输入元素：");
    input_arr(len, a);
    printf("查找结果是：%d\n", binarysearch(len, target, a));
    free(a);
    return 0;
}

int binarysearch(int size, int target, int *a)
{
    int left = 0, right = size - 1, mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2; // 一般不会溢出，但也可以写成left+(right-left)/2
        if (a[mid] > target)
        {
            right = mid - 1;
        }
        else if (a[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
void input_arr(int size, int *a)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", a + i);
    }
}
void if_malloc(int *a)
{
    if (a == NULL)
    {
        fprintf(stderr, "内存分配失败！");
        exit(EXIT_FAILURE);
    }
}
void input_check(int *val)
{
    while (1)
    {
        printf("请输入元素个数和要查找的元素：");
        while (scanf("%d", val))
        {
            if (*val > 0)
            {
                return;
            }
            else
            {
                puts("非法输入，元素个数必须大于0");
                while (getchar() != '\n')
                {
                    continue;
                }
            }
        }
        puts("非法输入，输入必须是int类型");
        while (getchar() != '\n')
        {
            continue;
        }
    }
}
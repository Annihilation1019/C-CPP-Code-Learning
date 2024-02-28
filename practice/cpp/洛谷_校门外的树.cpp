// 某校大门外长度为l的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在l的位置；数轴上的每个整数点，即0，1，2，……，l，都种有一棵树。由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。

#include <iostream>
struct coordinate
{
    int begin;
    int end;
};

void initialized(int *arr, int len);
void subway_region(coordinate *struc_arr, int num);
void execute_arr(int *arr, coordinate *stru_arr, int len, int num);
int num_tree(int *arr, int len);
void clear(int *arr, coordinate *stru_arr);
int main()
{
    using namespace std;
    int num, len;
    cin >> len >> num;
    int *tree = new int[len + 1];
    coordinate *subway = new coordinate[num];
    initialized(tree, len + 1);              // 初始化动态数组所有元素为1
    subway_region(subway, num);              // 确定修建地铁的区域
    execute_arr(tree, subway, len + 1, num); // 将修建地铁区域的元素覆盖为0
    cout << num_tree(tree, len + 1);         // 计算剩下的树
    clear(tree, subway);                     // 释放内存
    return 0;
}

void initialized(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = 1;
    }
}
void subway_region(coordinate *stru_arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        scanf("%d%d", &((stru_arr + i)->begin), &((stru_arr + i)->end));
    }
}
void execute_arr(int *arr, coordinate *stru_arr, int len, int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = (stru_arr + i)->begin; j <= (stru_arr + i)->end; j++)
        {
            arr[j] = 0;
        }
    }
}
int num_tree(int *arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}
void clear(int *arr, coordinate *stru_arr)
{
    delete[] arr;
    delete[] stru_arr;
}
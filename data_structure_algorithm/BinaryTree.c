#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
typedef struct BinTree
{
    ElemType data;
    struct BinTree *lchild, *rchild;
} BinTree;

Status BinTreeInit(BinTree **tree);
bool BinTreeIsEmpty(BinTree *tree);
Status BinTreeCreate(BinTree **tree, ElemType data);
Status BinTreeDestroy(BinTree *tree);
Status BinTreeInsert(BinTree **tree, ElemType data);
void PreOrderTraverse(BinTree *tree);
void InOrderTraverse(BinTree *tree);
void PosOrderTraverse(BinTree *tree);
Status BinTreeGetElem(BinTree *tree, ElemType aim, ElemType *e);

int main()
{
    BinTree *tree;
    BinTreeInit(&tree);
    BinTreeInsert(&tree, 5);
    BinTreeInsert(&tree, 3);
    BinTreeInsert(&tree, 7);
    BinTreeInsert(&tree, 2);
    BinTreeInsert(&tree, 4);
    BinTreeInsert(&tree, 6);
    BinTreeInsert(&tree, 8);
    PreOrderTraverse(tree);
    printf("\n");
    InOrderTraverse(tree);
    printf("\n");
    PosOrderTraverse(tree);
    printf("\n");
    BinTreeDestroy(tree);
    return 0;
}

Status BinTreeInit(BinTree **tree)
{
    *tree = NULL; // 指向空地址
    return OK;
}

bool BinTreeIsEmpty(BinTree *tree)
{
    if (tree == NULL)
        return true;
    else
        return false;
}

Status BinTreeCreate(BinTree **tree, ElemType data)
{
    *tree = (BinTree *)malloc(sizeof(BinTree));
    if (*tree != NULL)
    {
        (*tree)->data = data;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
    }
    else
    {
        fputs("failed to create!\n", stderr);
        return ERROR;
    }
    return OK;
}

Status BinTreeDestroy(BinTree *tree)
{
    if (!BinTreeIsEmpty(tree))
    {
        BinTreeDestroy(tree->lchild); // 先遍历左子树
        BinTreeDestroy(tree->rchild); // 后遍历右子树
        free(tree);                   // 若该节点无后件，则释放当前节点，调用栈弹出一层
    }
    return OK;
}

Status BinTreeInsert(BinTree **tree, ElemType data)
{
    if (*tree == NULL) // 如果根节点为空，那么创建根节点
    {
        return BinTreeCreate(tree, data);
    }
    else
    {
        /* 二叉搜索树 */
        /* 比根节点小的数插入到左边，大的插入到右边，相等则不插入 */
        if (data < (*tree)->data)
        {
            return BinTreeInsert(&((*tree)->lchild), data);
        }
        else if (data > (*tree)->data)
        {
            return BinTreeInsert(&((*tree)->rchild), data);
        }
        else
        {
            fputs("failed to insert!\n", stderr);
            return ERROR;
        }
    }
}

void PreOrderTraverse(BinTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    printf("%d ", tree->data);      // 先访问根节点
    PreOrderTraverse(tree->lchild); // 然后遍历左子树
    PreOrderTraverse(tree->rchild); // 最后遍历右子树
}

void InOrderTraverse(BinTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    InOrderTraverse(tree->lchild); // 先遍历左节点
    printf("%d ", tree->data);     // 后访问根节点
    InOrderTraverse(tree->rchild); // 最后遍历右节点
}

void PosOrderTraverse(BinTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    PosOrderTraverse(tree->lchild); // 先遍历左节点
    PosOrderTraverse(tree->rchild); // 然后遍历右节点
    printf("%d ", tree->data);      // 最后访问根节点
}

Status BinTreeGetElem(BinTree *tree, ElemType aim, ElemType *e)
{
    if (tree == NULL)
    {
        return ERROR;
    }
    if (tree->data == aim)
    {
        *e = tree->data;
    }
    PreOrderTraverse(tree->lchild); // 然后遍历左子树
    PreOrderTraverse(tree->rchild); // 最后遍历右子树
    return OK;
}

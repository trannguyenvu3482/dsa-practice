#include <stdio.h>

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} * TREE;

int themNode(TREE &t, int x)
{
    if (t == NULL)
    {
        t = new Node;
        t->data = x;
        t->left = NULL;
        t->right = NULL;
        return 1;
    }
    else
    {
        if (x < t->data)
        {
            return themNode(t->left, x);
        }
        else if (x > t->data)
        {
            return themNode(t->right, x);
        }
        else
        {
            return 0;
        }
    }
}

void nhapList(TREE &t)
{
    int n;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        printf("a[%d] = ", i);
        scanf("%d", &x);
        themNode(t, x);
    }
}

void duyetNLR(TREE t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        duyetNLR(t->left);
        duyetNLR(t->right);
    }
}

int main(int argc, char const *argv[])
{
    TREE t = NULL;

    nhapList(t);

    printf("\nList goc: ");
    duyetNLR(t);

    return 0;
}

#include <stdio.h>
#define MAX 100

struct node{
    int data;
    struct node *left, *right;
    int leftnull;
};

struct pair{
    struct node *last, *first;
};

struct pair *newpair(struct node *first, struct node *last) {
    struct pair *p = (struct pair *)malloc(sizeof(struct pair));
    p->last = last;
    p->first = first;
    return p;
}

struct node *newnode(int data, struct node *left, struct node *right) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = left;
    n->right = right;
    if (left == NULL)
        n->leftnull = 1;
    else
        n->leftnull = 0;
    return n;
}

struct node *aux(int a[], size_t len, size_t pos) {
    struct node *n;
    if (pos > len)
        return NULL;
    n = newnode(a[pos], aux(a, len, pos * 2), aux(a, len, pos * 2 + 1));
    return n;
}

struct node *build(int a[], size_t len) {
    return aux(a, len, 1);
}

struct node *setthread(struct node *n) {
    if (n->right == NULL && n->left == NULL) {
        return n;
    } else if (n->left == NULL) {
        n->left = n->right;
        return setthread(n->right);
    } else if (n->right == NULL) {
        return setthread(n->left);
    } else {
        setthread(n->left)->left = n->right;
        return setthread(n->right);
    }
}

int main(int argc, char **argv) {
    int tmp[MAX];
    struct node *root, *n;
    int index;

    for (index = 1; index < MAX; index++)
        scanf("%d", tmp + index);
    root = build(tmp, MAX - 1);

    setthread(root)->left == NULL;
    printf("PREORDER\n");
    for (n = root; n != NULL; n = n->left)
        printf("%d ", n->data);
    printf("\nEND PRERDER\n");

    return 0;
}

#include <stdio.h>
#define MAX 100

struct node{
    int data;
    struct node *left, *right;
};

struct node *newnode(int data, struct node *left, struct node *right) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = left;
    n->right = right;
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


void preoder(struct node *n) {
    if (n == NULL) {
        return;
    } else {
        printf("%d ", n->data);
        preoder(n->left);
        preoder(n->right);
    }
}

int main(int argc, char **argv) {
    int tmp[MAX];
    struct node *root, *n;
    int index;

    for (index = 1; index != MAX; index++)
    	scanf("%d", tmp + index);
    root = build(tmp, MAX - 1);

    printf("PREORDER\n");
    preoder(root);
    printf("\nEND PRERDER\n");

    return 0;
}
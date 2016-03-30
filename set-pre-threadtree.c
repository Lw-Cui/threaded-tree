#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
    int leftnull;
};

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

//TODO: ALWAYS maintain the left pointer
struct node *insert(struct node *n, int data) {
    if (n == NULL) {
        return newnode(data, NULL, NULL);
    } else if (data < n->data) {
        if (n->left)
            return insert(n->left, data);
        else
            return n->left = newnode(data, NULL, NULL);
    } else if (data > n->data) {
        if (n->right)
            return insert(n->right, data);
        else
            return n->right = newnode(data, NULL, NULL);
    } else {
        return NULL;
    }
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

void clear(struct node *p) {
    if (!p->leftnull) clear(p->left);
    if (p->right) clear(p->right);
    free(p);
}

int main(int argc, char **argv) {
    int data, flag = 1;
    struct node *root = NULL, *n;

    while (scanf("%d", &data) == 1)
        if (flag) {
            root = insert(root, data);
            flag = 0;
        } else {
            insert(root, data);
        }

    setthread(root)->left == NULL;
    printf("PREORDER\n");
    for (n = root; n != NULL; n = n->left)
        printf("%d ", n->data);
    printf("\nEND PRERDER\n");
    clear(root);
    return 0;
}

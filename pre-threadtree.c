#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
    int leftnull;
};

struct node *newnode(int data, struct node *left) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = left;
    n->right = NULL;
	n->leftnull = 1;
    return n;
}

void insert(struct node *n, int data) {
	struct node *leftleaf;

    if (data < n->data)
        if (n->leftnull) {
			n->leftnull = 0;
            n->left = newnode(data, n->left);
		} else {
            insert(n->left, data);
		}

    if (data > n->data)
        if (n->right) {
            insert(n->right, data);
		} else if (n->leftnull) {
            n->left = n->right = newnode(data, n->left);
		} else {
			leftleaf = n->left;
			while (leftleaf->left && leftleaf->left->data < n->data)
				leftleaf = leftleaf->left;
			leftleaf->left = n->right = newnode(data, leftleaf->left);
		}
}

void clear(struct node *p) {
    if (!p->leftnull) clear(p->left);
    if (p->right) clear(p->right);
    free(p);
}

int main(int argc, char **argv) {
    int data, flag = 1;
    struct node *root = NULL;
	struct node *n; // Iterator

    while (scanf("%d", &data) == 1)
        if (flag) {
            root = newnode(data, NULL);
            flag = 0;
        } else {
            insert(root, data);
        }

    printf("PREORDER\n");
    for (n = root; n != NULL; n = n->left)
        printf("%d ", n->data);
    printf("\nEND PRERDER\n");
    clear(root);

    return 0;
}

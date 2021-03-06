#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void preoder(struct node *n) {
    if (n == NULL) {
        return;
    } else {
        printf("%d ", n->data);
        preoder(n->left);
        preoder(n->right);
    }
}

void postoder(struct node *n) {
    if (n == NULL) {
        return;
    } else {
        postoder(n->left);
        postoder(n->right);
        printf("%d ", n->data);
    }
}

int main(int argc, char **argv) {
    int data, flag = 1;
    struct node *root = NULL, *n;

    while (scanf("%d", &data) == 1)
    	if (flag) {
    		root = insert(NULL, data);
    		flag = 0;
    	} else {
    		insert(root, data);
    	}

    if (!strcmp(argv[1], "pre")) {
        printf("PREORDER\n");
        preoder(root);
        printf("\nEND PRERDER\n");
    } else if (!strcmp(argv[1], "post")) {
        printf("POSTORDER\n");
        postoder(root);
        printf("\nEND POSTORDER\n");
    }

    return 0;
}
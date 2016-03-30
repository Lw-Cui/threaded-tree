#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
    struct node *prev, *next;
};

struct node *rawnode() {
    return (struct node *)malloc(sizeof(struct node));
}

struct node *newnode(int data, struct node* prev, struct node* next) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    n->prev = prev; n->prev->next = n; 
    n->next = next; n->next->prev = n;
    return n;
}

void insert(struct node *n, int data) {
	if (data < n->data) {
		if (n->left) {
			insert(n->left, data);
		} else if (n->right) {
			struct node *last = n->right;
			while (last->left || last->right)
				last = last->left? last->left: last->right;
			n->left = newnode(data, last->prev, last); 
		} else {
			n->left = newnode(data, n->prev, n);
		}
	}

	if (data > n->data) {
		if (n->right) {
			insert(n->right, data);
		} else if (n->left) {
			n->right = newnode(data, n->left, n);
		} else {
			n->right = newnode(data, n->prev, n);
		}
	}
}

void clear(struct node *p) {
    if (p->left) clear(p->left);
    if (p->right) clear(p->right);
    free(p);
}

int main(int argc, char **argv) {
    int data, flag = 1;
    struct node *root = NULL;
	struct node *beg = rawnode(), *end = rawnode();

    while (scanf("%d", &data) == 1)
        if (flag) {
            root = newnode(data, beg, end);
            flag = 0;
        } else {
            insert(root, data);
        }

    printf("POSTORDER\n");
    for (struct node *n = beg->next; n != end; n = n->next)
        printf("%d ", n->data);
    printf("\nEND POSTORDER\n");
    clear(root); clear(beg); clear(end);
    return 0;
}

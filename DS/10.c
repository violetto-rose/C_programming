#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left, *right;
};

typedef struct BST NODE;

NODE *create(NODE *node, int data) {
    if (node == NULL) {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < node->data) node->left = create(node->left, data);
    else if (data > node->data) node->right = create(node->right, data);
    return node;
}

NODE *search(NODE *node, int key) {
    if (node == NULL || node->data == key) return node;
    if (key < node->data) return search(node->left, key);
    return search(node->right, key);
}

void inorder(NODE *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NODE *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    NODE *root = NULL;
    int ch, data;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = create(root, data);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL)
                    printf("Element %d found\n", data);
                else
                    printf("Element %d not found\n", data);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure of a BST node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    // Duplicate values are ignored
    return root;
}

// Non-recursive Inorder Traversal
void inorder(struct Node *root)
{
    struct Node *stack[MAX];
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

// Non-recursive Preorder Traversal
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *stack[MAX];
    int top = -1;

    stack[++top] = root;

    while (top != -1)
    {
        struct Node *current = stack[top--];

        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Non-recursive Postorder Traversal
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *stack1[MAX];
    struct Node *stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        struct Node *current = stack1[top1--];

        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;

        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1)
    {
        printf("%d ", stack2[top2--]->data);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;
    int choice, i;

    int elements[] = {6, 9, 5, 2, 8, 15,
                      24, 14, 7, 8, 5, 2};

    int n = sizeof(elements) / sizeof(elements[0]);

    do
    {
        printf("\n\n----- BST NON-RECURSIVE TRAVERSALS -----\n");
        printf("1. Create BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                root = NULL;

                for (i = 0; i < n; i++)
                    root = insert(root, elements[i]);

                printf("BST created successfully.\n");
                break;

            case 2:
                if (root == NULL)
                    printf("Please create the BST first.\n");
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Please create the BST first.\n");
                else
                {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Please create the BST first.\n");
                else
                {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

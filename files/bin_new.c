#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls() (system("cls"))
#define pause() (system("pause"))

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *root = NULL;

node *add(node *root, int data)
{
    if (root == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return root;
    }
    else if (root->left == NULL)
    {
        root->left = add(root->left, data);
    }
    else if (root->right == NULL)
    {
        root->right = add(root->right, data);
    }
    else if (root->left->left == NULL || root->left->right == NULL)
    {
        root->left = add(root->left, data);
    }
    else
    {
        root->right = add(root->right, data);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void menu()
{
    int choice, data;
    cls();
    fflush(stdin);
    printf("\n1.Add\n2.Delete\n3.Search\n4.Pre-Order\n5.In-Order\n6.Post-Order\n7.Exit\n");
    scanf("%d", &choice);
    cls();
    if ((choice >= 2 && choice <= 6) && root == NULL)
    {
        printf("The tree is empty. ");
    }
    else
    {
        if (choice >= 1 && choice <= 3)
        {
            printf("Enter integer : ");
            scanf("%d", &data);
        }
        switch (choice)
        {
        case 1:
            root = add(root, data);
            break;
        // case 2:
        //     delete(root, data);
        //     break;
        // case 3:
        //     search(root, data);
        //     break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            exit(0);
        default:
            menu();
        }
    }
    pause();
    menu();
}

int main()
{
    menu();
    return 0;
}
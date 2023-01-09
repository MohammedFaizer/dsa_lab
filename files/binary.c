#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;
node* root=NULL;
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
void insert()
{
    int value;
    printf("Enter the element to be inserted:");
    scanf("%d",&value);
    if(root==NULL)
    {
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->left=NULL;
        newnode->right=NULL;
    }

}
int main()
{
    int choice;
    printf("-----Binary Tree-----\n");
    printf("1.Insertion\t 2.Deletion\t 3.Search\t 4.Inorder Traversal \t5.Preorder Traversal\t 6. Postorder Traversal\t 7.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        search();
        break;
        case 4:
        inorder();
        break;
        case 5:
        preorder();
        break;
        case 6:
        postorder();
        break;
        default:
        printf("Invalid Choice\n");
        break;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct node
{
struct node * left;
int data;
struct node * right;
};
int array[ ] = {1, 2, 3, 4, 5, 6, -1, -1, -1, -1 };
int leftcount[ ] = { 1, 3, 5, -1, -1, -1, -1, -1, -1, -1};
int rightcount[ ] = {2, 4, 6, -1, -1, -1, -1, -1, -1, -1};
struct node * BTree( int index )
{
struct node *temp = NULL;
if (index != -1) {
temp = (struct node *)malloc( sizeof ( struct node ) );
temp->data = array[index];
temp->left = BTree( leftcount[index] );
temp->right = BTree( rightcount[index] );
}
return temp;
}
void inorder( struct node *root ) {
if (root != NULL)
{
inorder(root->left);
printf("%d\t", root->data);
inorder(root->right);
}
}
void preorder( struct node *root ) {
if (root != NULL)
{
printf("%d\t", root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder( struct node *root ) {
if (root != NULL)
{
postorder(root->left);
printf("%d\t", root->data);
postorder(root->right);
}
}
void main()
{
struct node *root;
root = BTree( 0 );
printf("\n In-order Traversal :");
inorder(root);
printf(" \n Preorder Traversal :");
preorder(root);
printf(" \n Postorder Traversal :");
postorder(root);
}
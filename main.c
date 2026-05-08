
#include<stdio.h>
#include<stdlib.h>
struct BstNode* Insert(struct BstNode* root, int data);

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct BstNode* FindMax(struct BstNode *root){
    if(root==NULL){ 
        printf(" Tree is empty");
        return NULL;
    }
    else if( root->right==NULL)
        return root;
    else
        return FindMax(root->right);

}



struct BstNode* Insert(struct BstNode* root, int data){
    if(root==NULL){
        root=GetNewNode(data);    
    }
    else if(root->data>=data){
        root->left=Insert(root->left,data);
    }
    else 
        root->right=Insert(root->right,data);

return root;
}
void Inorder(struct BstNode* root){
    if(root==NULL)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
// REcursively finding the minimum
struct BstNode* FindMin(struct BstNode *root){
    if(root==NULL){ 
        printf(" Tree is empty");
        return NULL;
    }
    else if( root->left==NULL)
        return root;
    else
        return FindMin(root->left);

}



// iteratively finding the Minimum

struct BstNode* FindMaxIteratively(struct BstNode* root){

     struct BstNode *temp=root;
     if (temp==NULL)
        {
            printf(" Tree is empty");
            return NULL;
    }
    while (temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}


int main(){
 struct BstNode *root=NULL;

 root=Insert(root, 15);
 root=Insert(root, 10);
 root=Insert(root, 20);
 root=Insert(root, 8);
 root=Insert(root, 12);
 root=Insert(root, 17);
 root=Insert(root, 25);
 Inorder(root);
 struct BstNode* min=FindMin(root);
 struct BstNode* minIteratively=FinMinIteratively(root);
 
printf("\n %d is the minimum value of Binary Search Tree",min->data);

printf("\n %d is the minimum value of Binary Search Tree",minIteratively->data);






}
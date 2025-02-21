//
// Created by salma on 11/9/2024.
//
#include<bits/stdc++.h>

using namespace std;



struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

TreeNode *tree=nullptr;

struct TreeNode* iterTree(struct TreeNode* parentptr, struct TreeNode* newNode);

void insertElement(){
    int num; TreeNode *newNode;
    printf("add number in BST: ");
    scanf("%d", &num);
    newNode = new TreeNode();

    newNode->data = num;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if(tree==nullptr){
        tree = newNode;
    }else{
        iterTree(tree, newNode);
    }

}

struct TreeNode* iterTree(struct TreeNode* parentptr, struct TreeNode* newNode){
    if(parentptr == nullptr){
       return newNode;
    }
    if(newNode->data <= parentptr->data){
        parentptr->left = iterTree(parentptr->left, newNode);
    }else{
        parentptr->right = iterTree(parentptr->right, newNode);
    }

    return parentptr;
}

 void preOrderTraversal(struct TreeNode* nodeptr){
    if(nodeptr != nullptr){
        printf("%d\n", nodeptr->data);
        preOrderTraversal(nodeptr->left);
        preOrderTraversal(nodeptr->right);
    }
}

void invertBinaryTree(struct TreeNode* nodeptr){
    TreeNode* temp = new TreeNode();
    if(nodeptr!=nullptr){
        invertBinaryTree(nodeptr->left);
        invertBinaryTree(nodeptr->right);
        temp = nodeptr->left;
        nodeptr->left = nodeptr->right;
        nodeptr->right = temp;
    }
}

int maxDepth(TreeNode* root) {
    TreeNode* nodeptr = new TreeNode();
    nodeptr = root;
    int leftHeight, rightHeight;
    if(nodeptr == nullptr){
        return 0;
    }
    leftHeight = maxDepth(nodeptr->left);
    rightHeight = maxDepth(nodeptr->right);

    if(leftHeight>rightHeight){
        return leftHeight+1;
    }else{
        return rightHeight+1;
    }
}

int main(){
    int choice=1;
    do{
        printf("Enter your option\n");
        printf("1. Insert new element\n");
        printf("2. Print tree\n");
        printf("3. Invert tree\n");
        printf("4. Height / Max Depth of tree\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: insertElement(); break;
            case 2:
                if(tree==nullptr){
                    printf("Tree is empty\n");
                }
                preOrderTraversal(tree);
                break;
            case 3:
                invertBinaryTree(tree);
                break;
            case 4:
                int height;
                height = maxDepth(tree);
                cout << "Max depth / height of tree is: " << height << endl;
        }
    }while(choice!=-1);
}
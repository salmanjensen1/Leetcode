//
// Created by salma on 6/25/2024.
//

#include<bits/stdc++.h>

using namespace std;

//constant & global variables
struct Node {   //Node struct declaration
    int data;
    struct Node* next;
};

Node* start = NULL; //initialize start to NULL
//method declarations
Node* create_ll(Node *start);
void display_ll(Node* start);

int main(){
    start = create_ll(start);
    display_ll(start);
}

Node* create_ll(Node *start){
    int num;
    Node *new_node, *ptr;
    printf("Enter data\n");
    scanf("%d", &num);

    while(num!= -1){
        new_node = new Node();
        new_node->data=num;

        if(start==NULL){
            start = new_node;
            new_node->next=NULL;
            cout << 1 << " Here";
        }
        else{
            ptr=start;

            cout << 2 << " Here";
            while(ptr->next!=NULL){
                cout << 3 << " Here";
                printf("%d", ptr->data);
                ptr = ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }

        printf("Enter the next data\n");
        scanf("%d", &num);
    }
    return start;
}

void display_ll(Node* start){
    Node *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("%d", ptr->data);
        ptr=ptr->next;
    }
}
//
// Created by salma on 6/25/2024.
//

#include<bits/stdc++.h>

using namespace std;

//constant & global variables
struct ListNode {   //ListNode struct declaration
    int val;
    struct ListNode* next;
};

ListNode* start = NULL; //initialize start to NULL
//method declarations
ListNode* create_ll(ListNode *start);
void display_ll(ListNode* start);

ListNode* iterateTillEnd(ListNode* ptr){
    ListNode* prev=ptr;
    while(ptr->next!=nullptr){
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=nullptr;
    return ptr;

}

void reorderList(ListNode* head) {
    ListNode *next, *ptr, *prev;

    ptr = head;

    while(ptr->next != nullptr || (ptr->next)->next != nullptr){
        prev=ptr->next;
        ptr->next = iterateTillEnd(ptr->next);
        cout << "val: " << (ptr->next)->val;
        (ptr->next)->next = prev;
        ptr=prev;

    }

}


int main(){
    start = create_ll(start);
    reorderList(start);
    display_ll(start);
}



ListNode* create_ll(ListNode *start){
    int num;
    ListNode *new_node, *ptr;
    printf("Enter val\n");
    scanf("%d", &num);

    while(num!= -1){
        new_node = new ListNode();
        new_node->val=num;

        if(start==NULL){
            start = new_node;
            new_node->next=NULL;
        }
        else{
            ptr=start;

            while(ptr->next!=NULL){
                printf("%d", ptr->val);
                ptr = ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }

        scanf("%d", &num);
    }
    return start;
}

void display_ll(ListNode* start){
    ListNode *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("%d", ptr->val);
        ptr=ptr->next;
    }
}
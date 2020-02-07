/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int readNumber(struct ListNode* l){
    int i = 1;
    int total = 0;
    for (struct ListNode *temp = l; temp != NULL; temp = temp->next, i *= 10){
        total += i*(temp->val);
    }
    return total;
}

struct ListNode* transform(int num){
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    head->val = num%10;
    
    num /= 10;
    
    while(num != 0){
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = num%10;
        tail->next = temp;
        tail = temp;
        num /= 10;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int num1 = readNumber(l1);
    int num2 = readNumber(l2);
    return transform(num1 + num2);
}

void printNumber(struct ListNode *l){
    for (struct ListNode *temp = l; temp != NULL; temp = temp->next){
        printf("%d ", temp->val);
    }
    printf("\n");
}
int main()
{
    struct ListNode *num1 = transform(342);
    struct ListNode *num2 = transform(465);
    printNumber(addTwoNumbers(num1, num2));
    return 0;
}
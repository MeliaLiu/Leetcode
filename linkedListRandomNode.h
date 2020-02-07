/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <time.h>

typedef struct {
    struct ListNode* _head;
    int _length;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

Solution* solutionCreate(struct ListNode* head) {
    Solution* temp = (Solution*)malloc(sizeof(Solution));
    temp->_head = head;
    temp->_length = 0;
    for (struct ListNode* ptr = head; ptr != NULL; ptr = ptr->next){
        temp->_length++;
    }
    return temp;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    srand(rand());
    int random = rand() % obj->_length;
    struct ListNode* ptr = obj->_head;
    for (int i = 0;i < random; i++){
         ptr = ptr->next;
    }
    return ptr->val;
}

void solutionFree(Solution* obj) {
    struct ListNode* temp = obj->_head;
    while (obj->_head != NULL){
        obj->_head = obj->_head->next;
        free(temp);
        temp = obj->_head;
    }
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
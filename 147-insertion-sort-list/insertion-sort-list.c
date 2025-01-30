struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        // At each iteration, we insert an element into the resulting list.
        struct ListNode* prev = dummy;
        // find the position to insert the current node
        while (prev->next != NULL && prev->next->val <= curr->val) {
            prev = prev->next;
        }
        struct ListNode* next = curr->next;
        // insert the current node to the new list
        curr->next = prev->next;
        prev->next = curr;
        // moving on to the next iteration
        curr = next;
    }
    return dummy->next;
}
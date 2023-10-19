#include<bits/stdc++.h>
using namespace std;

struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    ListNode* t1 = list1;
    ListNode* t2 = list2;

    while (t1 && t2) {
        if (t1->val < t2->val) {
            curr->next = t1;
            t1 = t1->next;
        } else {
            curr->next = t2;
            t2 = t2->next;
        }
        curr = curr->next;
    }

    if (t1) {
        curr->next = t1;
    }
    if (t2) {
        curr->next = t2;
    }

    ListNode* result = dummy->next;
    delete dummy;
    return result;
}


int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    //int n; cin>>n;

    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    ListNode *head2 = new ListNode(1);
    ListNode *temp2 = head2;

    //int n; cin>>n;

    for(int i = 2; i <= 5; i++){
        temp2->next = new ListNode(i);
        temp2 = temp2->next;
    }

    ListNode* merged = mergeTwoLists(head, head2);

    print(merged);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class doublyNode{
    public:
    int data;
    doublyNode *next;
    doublyNode * prev;
    doublyNode(int a):data(a),next(nullptr),prev(nullptr){}
};

void insertAtStart(ListNode*& head, int val) {
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node; 
}

void insertAtEnd(ListNode* head, int val) {
    ListNode* temp = head;

    while (temp->next) {
        temp = temp->next;
    }

    ListNode* node = new ListNode(val);

    temp->next = node;
}

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


void deletefromStart(ListNode*& head) {
    if (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


void deleteFromEnd(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return;
    }

    ListNode* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

ListNode* reverse(ListNode* head){
    if(head->next == NULL) return head;
    
    ListNode* newHead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead; 
}

ListNode* middleNode(ListNode* head) {
    ListNode *slow= head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *dummy = new ListNode();
    ListNode *t1 = list1, *t2 = list2, *curr = dummy;

    while (t1 && t2) {
        if (t1->val >= t2->val) {
            curr->next = t2;
            curr = t2;
            if (t2->next != nullptr)
                t2 = t2->next;
            else
                break;
        } else {
            curr->next = t1;
            curr = t1;
            if (t1->next != nullptr)
                t1 = t1->next;
            else
                break;
        }
    }

    if (t1)
        curr->next = t1;
    if (t2)
        curr->next = t2;

    ListNode* result = dummy->next;
    delete dummy;
    return result;
}

bool isPalindrome(head){
    ListNode* mid = middleNode(head);

    ListNode* temp = head;
    while(temp->val != mid->val){
        temp = temp->next;
    }

    ListNode* lastHalf = reverse(mid);

    temp = head;
    ListNode* temp2 = lastHalf;

    while(temp2 -> next){
        if(temp2 -> val != temp->next) return false;
    }

    return true;
}

int nthnodeFromEnd(node * head,int n){
    int cnt=0;

    node *temp= head;

    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }

    temp=head;
    
    for(int i =1;i<=(cnt-n);i++){
        temp=temp->next;
    }
    return temp->data;

}

int main() {
    ListNode* head = new ListNode(5);

    // Insert nodes at the start and end.
    print(head);
    insertAtStart(head, 6);
    insertAtEnd(head, 4);
    insertAtEnd(head, 4);
    insertAtEnd(head, 4);
    insertAtStart(head, 6);

    // Delete nodes from the start and end.
    deletefromStart(head);
    deleteFromEnd(head);

    // Print the modified list.
    print(head);

    //reverse list
    ListNode* rev = reverse(head);
    print(rev);

    //find middle
    ListNode* middle = middleNode(head);
    print(middle);

    //merge2lists
    ListNode* list1 = new ListNode(2);
    mergeTwoLists(head, list1);

    return 0;
}

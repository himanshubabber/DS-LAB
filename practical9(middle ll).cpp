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

ListNode* middle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    //1 2 3 4 5

    while(fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    //int n; cin>>n;

    for(int i = 2; i <= n; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    ListNode* mid = middle(head);
    cout<< mid->val <<endl;
    return 0;
}
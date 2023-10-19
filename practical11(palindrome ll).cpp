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

bool checkPalindrome(ListNode* head) {
    stack<int> st;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast){
        slow = slow->next;
    }

    while(slow){
        if (slow->val != st.top()) {
            return false;
        }
        slow = slow->next;
        st.pop();
    }

    return true;
}


int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    //int n; cin>>n;

    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    for(int i = 5; i >= 1; i--){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    bool ans = checkPalindrome(head);

    cout<<ans<<endl;
    
    return 0;
}
/*
 * @Author: yao fanghao
 * @Date: 2023-08-22 11:23:45
 * @LastEditTime: 2023-08-22 13:46:32
 * @LastEditors: yao fanghao
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLists(ListNode* node){
    while (node != nullptr) {
        ListNode* temp = node;
        int value = node->val; 
        cout << value << " ";
        node = node->next; 
        delete temp;
    }
    cout<<endl;
    node = nullptr;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode* createLinkedList() {
    ListNode* head = nullptr;  // 头指针
    ListNode* tail = nullptr;  // 尾指针

    int n; 
    cout<<"input number of nodes:"<<endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value); 
        if (head == nullptr) {
            head = newNode;  
            tail = newNode;
        } else {
            tail->next = newNode; 
            tail = newNode; 
        }
    }
    cout<<"success create linked-list!"<<endl;

    return head;
}
int main(){
    // ListNode* node1 = createLinkedList();
    // ListNode* head1 = new ListNode(1);
    // ListNode* second1 = new ListNode(2);
    // ListNode* third1 = new ListNode(3);
    // head1->next = second1;
    // second1->next = third1;

    // ListNode* head2 = new ListNode(1);
    // ListNode* second2 = new ListNode(3);
    // ListNode* third2 = new ListNode(4);
    // head2->next = second2;
    // second2->next = third2;

    ListNode* head1 = createLinkedList();
    ListNode* head2 = createLinkedList();

    printLists(head1);
    printLists(head2);

    ListNode* head3 = mergeTwoLists(head1, head2);

    printLists(head3);

    return 0;

}
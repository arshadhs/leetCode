//2095. Delete the Middle Node of a Linked List

#include<iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    //2095. Delete the Middle Node of a Linked List
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return NULL;
        ListNode* prev = new ListNode(0, head);
        ListNode* slow = prev;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        free(temp);
        ListNode* newHead = prev->next;
        free(prev);
        return newHead;
    }

    // ListNode* deleteMiddle(ListNode* head) {
    //     ListNode* curr = head;
    //     int size = 0;
    //     while (curr != nullptr) {
    //         curr = curr->next;
    //         size++;
    //     }
    //     ListNode* prev = nullptr;
    //     curr = head;
    //     for (int i = 0; i <  size/2; i++) {
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     prev->next = curr->next;
    //     delete(curr);
    //     return head;
    // }
    
    void insertAtEnd(int x, ListNode* start)
    {
        if (start == nullptr) 
            start = new ListNode(x);
        else {
            ListNode *temp = start;
            while (temp->next != nullptr)
                temp = temp->next;
            
            temp->next = new ListNode(x);
        }
        return;
    }

    void displayList(ListNode *head)
    {
        cout << endl;
        ListNode *temp = head;
        while(temp != nullptr)
        {
            cout << "\t" << temp->val;
            temp = temp->next;
        }
    }
};

int main() {

    ListNode *start;

    start = new ListNode(5);
    
    Solution obj;
    // obj.insertAtEnd(9, start);
    // obj.insertAtEnd(6, start);
    // obj.insertAtEnd(4, start);
    // obj.insertAtEnd(3, start);
    // obj.insertAtEnd(2, start);
    // obj.insertAtEnd(1, start);
    obj.displayList(start);
    
    ListNode* newList = obj.deleteMiddle(start);

    obj.displayList(newList);
    return 0;
}
// Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;            
        }

        return prev;
    }

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
    
    ListNode *rev = obj.reverseList(start);

    obj.displayList(rev);

 //   ListNode* newList = obj.deleteMiddle(rev);

 //   obj.displayList(newList);
    return 0;
}
#include <bits/stdc++.h>
#include <array>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Time complexity --> O(n^2)
    // SPACE complexity --> O(1)
    ListNode* removeDuplicates(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* tempHead=head;
        
        while(tempHead!=NULL){
            int val=tempHead->val;
            auto temp=tempHead;
            while(temp!=NULL && temp->next!=NULL){
                cout<<temp->val<<" "<<endl;
                if(temp->next->val==val){
                    auto toDelete=temp->next;
                    temp->next=temp->next->next;
                    delete toDelete;
                }
                else temp=temp->next;
            }
            tempHead=tempHead->next;
        }
        return head;
    }

    
};


int main()
{
    ListNode* head=new ListNode(2);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(1);
    head->next->next->next->next->next=new ListNode(9);
    head->next->next->next->next->next->next=new ListNode(0);
    auto res=head;
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }

    Solution s;
    ListNode* result=s.removeDuplicates(head);
    while(result!=NULL){
        cout<<result->val<<" ";
        result=result->next;
    }

    while(head != NULL){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
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
    // TC- O(n)
    // SC - O(n)
    ListNode* sortList(ListNode* head) {
        map<int,int> mp;
        ListNode* temp=head;
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        for (auto &it:mp){
            while(it.second--){
                temp->val=it.first;
                temp=temp->next;
            }
        }
        return head;
    }
    
    // merge sort in linked list 
    // TC - O(nlogn)
    // SC - O(1)
    ListNode* merge(ListNode* slow, ListNode* fast){
        ListNode dummy(0);
        ListNode* ptr= &dummy;
        while(slow && fast){
            if(slow->val<fast->val){ptr->next=slow; slow=slow->next;}
            else {ptr->next=fast; fast=fast->next;}
            ptr=ptr->next;
        }

        while(slow){ptr->next=slow; slow=slow->next; ptr=ptr->next;}
        while(fast){ptr->next=fast; fast=fast->next; ptr=ptr->next;}
        ptr=&dummy;
        ptr=ptr->next;
        return ptr;
    }

   ListNode* mergeSort(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* prev=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode* l1=mergeSort(head);
        ListNode* l2=mergeSort(slow);

        return merge(l1,l2);
    }
};

int main()
{
    return 0;
}
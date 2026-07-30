/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
       
        int sum=0,carry=0;
        ListNode dummy(-1);
        ListNode *temp=&dummy;
        while (list1 || list2 || carry){
            sum=carry;
            if(list1){
               sum += list1->val ;
               list1=list1->next;
            }
            if(list2){
                sum += list2->val ;
                 list2=list2->next;
            }
                carry=sum/10;
                sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        return dummy.next;
    } 
};     
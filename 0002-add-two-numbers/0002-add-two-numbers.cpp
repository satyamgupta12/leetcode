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
    ListNode* reverse(ListNode* head){
         ListNode *prev=NULL,*cur=head,*next;
        if(head==NULL || head->next==NULL) return head;

        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        // ListNode* head1=reverse(l1);
        // ListNode* head2=reverse(l2);

        int carry=0;
        ListNode* curr=NULL,*temp;
        while(head1 || head2){
            if (head1 && head2){
                int sum=head1->val+head2->val+ carry;
                carry=sum/10;
                int n=sum%10;
                temp = new ListNode(n);
                temp->next=curr;
                head1=head1->next;
                head2=head2->next;
            }
            else if(head1){
                int sum=head1->val+carry;
                carry=sum/10;
                int n=sum%10;
                temp = new ListNode(n);
                temp->next=curr;
                head1=head1->next;
            }
            else {
                int sum=head2->val+carry;
                carry=sum/10;
                int n=sum%10;
                temp = new ListNode(n);
                temp->next=curr;
                head2=head2->next;
            }
            curr=temp;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
                temp->next=curr;
                curr=temp;
        }
        curr=reverse(curr);
        return curr;
    }
};
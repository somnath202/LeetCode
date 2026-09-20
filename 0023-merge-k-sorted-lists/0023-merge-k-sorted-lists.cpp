class Solution {
private:
    ListNode* merge(ListNode* lists1, ListNode* lists2) {

        auto temp1 = lists1;
        auto temp2 = lists2;

        ListNode* ans = new ListNode();
        auto dummy = ans;

        while(temp1 != NULL && temp2 != NULL) {

            if(temp1->val <= temp2->val) {

                dummy->next = temp1;
                dummy = dummy->next;

                temp1 = temp1->next;
            }
            else {

                dummy->next = temp2;
                dummy = dummy->next;

                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL) {

            dummy->next = temp1;
            dummy = dummy->next;

            temp1 = temp1->next;
        }

        while(temp2 != NULL) {

            dummy->next = temp2;
            dummy = dummy->next;

            temp2 = temp2->next;
        }

        return ans->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        if(n == 0)
            return nullptr;

        ListNode* temp = lists[0];

        for(int i = 1; i < n; i++) {

            temp = merge(temp, lists[i]);
        }

        return temp;
    }
};
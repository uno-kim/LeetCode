/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> n1, n2, sum;
        ListNode* node = l1;
        while (node != NULL)
        {
            n1.push_back(node->val);
            node = node->next;
        }
        node = l2;
        while (node != NULL)
        {
            n2.push_back(node->val);
            node = node->next;
        }
        int loop = min(n1.size(), n2.size());
        for (int i = 0; i < loop; ++i)
            sum.push_back(n1[i] + n2[i]);
        if (n1.size() > n2.size())
        {
            for (int i = loop; i < n1.size(); ++i)
                sum.push_back(n1[i]);
        }
        else if (n2.size() > n1.size())
        {
            for (int i = loop; i < n2.size(); ++i)
                sum.push_back(n2[i]);
        }
        loop = sum.size();
        for (int i = 0; i < loop - 1; ++i)
        {
            if (sum[i] > 9)
            {
                sum[i] -= 10;
                sum[i + 1]++;
            }
        }
        if (sum[loop - 1] > 9)
        {
            sum[loop - 1] -= 10;
            sum.push_back(1);
        }
        ListNode* ret = NULL;
        if (sum.size() == 0) return ret;
        ret = new ListNode(sum[0]);
        ListNode* cur = ret;
        loop = sum.size();
        for (int i = 1; i < loop; ++i)
        {
            ListNode* node = new ListNode(sum[i]);
            cur->next = node;
            cur = cur->next;
        }
        return ret;
    }
};

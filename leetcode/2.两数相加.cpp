struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head;
		ListNode* cur = &head;
		int add = 0;
		while (l1 != nullptr && l2 != nullptr) {
			int e = l1->val + l2->val + add;
			if (e >= 10) {
				ListNode* nxt = new ListNode(e % 10);
				cur->next = nxt;
				cur = nxt;
				add = 1;
			} else {
				ListNode* nxt = new ListNode(e % 10);
				cur->next = nxt;
				cur = nxt;
				add = 0;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 == nullptr && l2 != nullptr) {
			int e = l2->val + add;
			ListNode* nxt = new ListNode(e % 10);
			if (e >= 10)
				add = 1;
			else
				add = 0;
			cur->next = nxt;
			cur = nxt;
			l2 = l2->next;
		}
		while (l1 != nullptr && l2 == nullptr) {
			int e = l1->val + add;
			ListNode* nxt = new ListNode(e % 10);
			if (e >= 10)
				add = 1;
			else
				add = 0;
			cur->next = nxt;
			cur = nxt;
			l1 = l1->next;
		}
		if (add == 1) {
			ListNode* nxt = new ListNode(add);
			cur->next = nxt;
			cur = nxt;
			cur->next = nullptr;
		}
		return head.next;
	}
};

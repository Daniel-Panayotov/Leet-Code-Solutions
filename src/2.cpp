struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* curr = new ListNode();
	ListNode* result = curr;

	int sum = 0;
	int carry = 0;
	while (l1 || l2 || carry) {
		sum = carry;

		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}

		if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}

		carry = 0;
		if (sum > 9) carry = 1;

		curr->val = sum % 10;
		if (l1 || l2 || carry) curr->next = new ListNode();
		curr = curr->next;
	}

	return result;
}
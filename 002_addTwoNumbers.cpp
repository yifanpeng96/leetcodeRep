//2. 两数相加
//
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是
//
//按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

//Tips:
//1. while (l1 || l2) 等价 while (l1 != nullptr || l2 != nullptr)
//2. int n1 = l1 ? l1->val : 0; 若l1 != nullptr则n1 == l1->val, 否则n1 == 0

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr && l2 == nullptr)
		return nullptr;

	ListNode* head = l1;
	while (true) {
		l1->val += l2->val;
		
		if (l1->val > 9) {
			l1->val %= 10;
			if (l1->next != nullptr)
				++l1->next->val;
			else
				l1->next = new ListNode(1);
		}
		if (l1->next == nullptr || l2->next == nullptr)
			break;
		l1 = l1->next;
		l2 = l2->next;
	}

	if (l2->next != nullptr)
		l1->next = l2->next;

	while (l1->next != nullptr && l1->next->val > 9) {
		l1 = l1->next;
		l1->val %= 10;
		if (l1->next != nullptr)
			++l1->next->val;
		else
			l1->next = new ListNode(1);
	}
	return head;
}

int main() {


	return 0;
}

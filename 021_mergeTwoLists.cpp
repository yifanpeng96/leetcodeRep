//21. 合并两个有序链表
//
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

//Tips:
//在2个链表前设一个preHead节点可避免改变head的情况

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* preHead = new ListNode(0);
	ListNode* prev = preHead;

	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val < l2->val) {
			prev->next = l1;
			l1 = l1->next;
		}
		else {
			prev->next = l2;
			l2 = l2->next;
		}
		prev = prev->next;
	}
	prev->next = l1 == nullptr ? l2 : l1;

	return preHead->next;
}

int main() {
	

	return 0;
}

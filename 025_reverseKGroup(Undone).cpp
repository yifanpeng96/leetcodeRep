//25. K 个一组翻转链表
//
//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
// k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//进阶：
//
//你可以设计一个只使用常数额外空间的算法来解决此问题吗？
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

//Tips:
//

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

pair<ListNode*, ListNode*> reverseList(ListNode* head, int k) {
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while (cur != nullptr && k > 0) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		--k;
	}
	cout << pre << endl;
	return { pre, cur };
}

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* reverseHead = new ListNode();
	ListNode* nextGroupHead = new ListNode();
	pair<ListNode*, ListNode*>(reverseHead, nextGroupHead) = reverseList(head, k);

	while (nextGroupHead != nullptr) {
		ListNode* node1;
		ListNode* node2;
		pair<ListNode*, ListNode*>(node1, node2) = reverseList(nextGroupHead, k);
		head->next = node1;
		head = nextGroupHead;
		nextGroupHead = node2;
	}
	return reverseHead;
}


int main() {
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4); 
	ListNode* node5 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode* head = reverseKGroup(node1, 2);

	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;

	return 0;
}

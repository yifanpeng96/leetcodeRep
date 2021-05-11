//19. 删除链表的倒数第 N 个结点
//
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
//进阶：你能尝试使用一趟扫描实现吗？

//Tips:
//1. 在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），
//   它的 next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。
//2. 快慢指针
//3. new出来的指针在最后记得delete掉并置为空

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummyNode = new ListNode(0);
	dummyNode->next = head;
	ListNode* slow = dummyNode;
	ListNode* fast = dummyNode;
	
	int count = 0;
	while (count < n) {
		fast = fast->next;
		++count;
	}
	while (fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;

	ListNode* ans = dummyNode->next;
	delete dummyNode;
	dummyNode = nullptr;
	return ans;
}

int main() {
	

	return 0;
}

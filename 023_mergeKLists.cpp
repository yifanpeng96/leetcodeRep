//23. 合并K个升序链表
//
//给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。

//Tips:
//分治法
//将 k 个链表配对并将同一对中的链表合并；
//第一轮合并以后， k 个链表被合并成了 k/2 个链表，然后是 k / 4个链表，k / 8 个链表等等；
//重复这一过程，直到得到最终的有序链表。


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//合并2个有序链表
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
	if (a == nullptr || b == nullptr)
		return a ? a : b;
	ListNode* preHead = new ListNode();
	ListNode* ptr = preHead, * aPtr = a, * bPtr = b;

	while (aPtr != nullptr && bPtr != nullptr) {
		if (aPtr->next < bPtr->next) {
			ptr->next = aPtr;
			aPtr = aPtr->next;
		}
		else {
			ptr->next = bPtr;
			bPtr = bPtr->next;
		}
		ptr = ptr->next;
	}
	ptr->next = (aPtr ? aPtr : bPtr);
	return preHead->next;
}

//自顶向下分治
ListNode* merge(vector<ListNode*>& lists, int left, int right) {
	if (left == right) return lists[left];
	if (left > right) return nullptr;

	int mid = (left + right) >> 1;
	return mergeTwoLists(merge(lists, 1, mid), merge(lists, mid + 1, right));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	return merge(lists, 0, lists.size() - 1);
}

int main() {
	

	return 0;
}

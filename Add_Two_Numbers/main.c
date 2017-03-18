#include "ListNode.h"
#include <stdlib.h>
#include "solution.h"

struct ListNode* getListNodes(int*, int);

int main(int argc, char* argv[]) {
	int a[2] = { 9, 9 }, b[3] = { 9, 9, 9};

	struct ListNode* listA = getListNodes(a, 2);
	struct ListNode* listB = getListNodes(b, 3);

	struct ListNode* result = addTwoNumbers(listA, listB);

	return 0;
}

struct ListNode* getListNodes(int* input, int arrSize) {
	struct ListNode* ret = NULL;
	struct ListNode* traverse = NULL;

	for (int i = 0; i < arrSize; i++) {
		struct ListNode* aNode = (struct ListNode*)malloc(sizeof(struct ListNode));

		aNode->next = NULL;
		aNode->val = input[i];

		if (ret == NULL) {
			ret = aNode;
			traverse = aNode;
		}
		else {
			traverse->next = aNode;
			traverse = traverse->next;
		}
	}

	return ret;
}
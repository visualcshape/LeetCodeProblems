#include "solution.h"
#include <stdlib.h>

typedef struct ListNode sListNode;

sListNode* addTwoNumbers(sListNode* nodes1, sListNode* nodes2) {
	int digitNodes1 = 0;
	int digitNodes2 = 0;
	sListNode* resultNodes = NULL;
	sListNode* resultBegin = NULL;
	
	int carry = 0;
	while(nodes1||nodes2) {
		int digitN1 = 0;
		int digitN2 = 0;

		if (nodes1 != NULL) {
			digitN1 = nodes1->val;
			nodes1 = nodes1->next;
		}

		if (nodes2 != NULL) {
			digitN2 = nodes2->val;
			nodes2 = nodes2->next;
		}

		int digitSum = digitN1 + digitN2 + carry;
		int resultDigit = digitSum % 10;
		carry = digitSum / 10;

		sListNode* aResultNode = (sListNode*)malloc(sizeof(sListNode));
		aResultNode->val = resultDigit;
		aResultNode->next = NULL;
		if (resultNodes == NULL) {
			resultBegin = aResultNode;
			resultNodes = aResultNode;
		}
		else {
			resultNodes->next = aResultNode;
			resultNodes = resultNodes->next;
		}
	}

	if (carry != 0) {
		sListNode* additionalNode = (sListNode*)malloc(sizeof(sListNode));
		additionalNode->next = NULL;
		additionalNode->val = carry;
		resultNodes->next = additionalNode;
	}

	return resultBegin;
}
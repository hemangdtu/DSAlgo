/* This is the ListNode class definition

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
*/

void printLinkedList (ListNode* head) {
    if(head == NULL) return;
	while(head != NULL)
	{
		cout << head -> data << " ";
		head = head -> next;
	}
}
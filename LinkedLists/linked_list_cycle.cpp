#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
}


ListNode* create_looped(int arr[], int loop_pos)
{
	
}



int main(int argc, char const *argv[])
{
	
	int data[] = {3,2,0,-4};
	int pos = 1;
	ListNode* head = create_looped(data,pos);

 
	return 0;
}

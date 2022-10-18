/*   Given a singly linked list of integers, reverse it using recursion and return the head to the modified list.
 You have to do this in O(N) time complexity where N is the size of the linked list.

Sample Input 1 :
2
10 -1
10 20 30 40 50 -1

Sample Output 1 :
10 
50 40 30 20 10
*/

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL||head->next==NULL) {
        return head;
    }
   
    Node *ans = reverseLinkedListRec(head -> next);
    Node *temp = ans;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return ans;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}

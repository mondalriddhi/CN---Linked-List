//bubble sort iterative
/*  Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Sample Input 1 :
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10 

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

int length(Node *head)
{
    //Write your code here
    int totlen = 0;
    Node *temp = head;
    while(temp!=NULL) {
        temp = temp -> next;
        totlen++;
    }
    return totlen;
}

Node *bubbleSort(Node *head)
{
	// Write your code here
	
    for(int i= 0; i < length(head); i++) {
        Node *prev = NULL, *current = head;
        while(current -> next!=NULL) {
            if(current -> data > current -> next -> data) {
                if(prev!=NULL) {
                    Node *temp = current -> next -> next;
                    prev -> next = current -> next;
                    prev -> next -> next = current;
                    current -> next = temp;
					prev = prev -> next;   //updating prev because its not going to enter the outer else condition
                }
                else {
                    head = current -> next;
                    current -> next = head -> next;
                    head -> next = current;
                    prev = head;    //updating prev because its not going to enter the outer else condition
                }
            }
            else {
                prev = current;
                current = current -> next;
            }
            
        	}
    }
    return head;
}

int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}

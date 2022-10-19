/*   For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers.
 The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. 
Only return the new head to the list.

Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
********************
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1

Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
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

Node *evenAfterOdd(Node *head)
{
    if(head==NULL||head -> next == NULL) {
        return head;
    }
	//write your code here
    Node *temp = head;
    Node *oh = NULL;
    Node *ot = NULL;
    Node *eh = NULL;
    Node *et = NULL;
    while(temp!=NULL) {
        if(temp -> data % 2 !=0) {
            if(oh==NULL) {
                oh = temp;
                ot = temp;
            }
            else {
                ot -> next = temp;
                ot = ot -> next;
            }
        }
        else {
            if(eh==NULL) {
                eh = temp;
                et = temp;
            }
            else {
                et -> next = temp;
                et = et -> next;
            }
        }
        temp = temp -> next;
    }
    
    if(oh!=NULL&&eh!=NULL) {
    	ot -> next = NULL;
    	et -> next = NULL;   
        
        ot -> next = eh;  //linkng the odd_tail with the even_head
    	Node *anslist = oh;
    	return anslist;
    }
    
    if(oh==NULL) {
        return eh;
    }
    if(eh==NULL) {
        ot -> next = NULL;
        return oh;
    }
    
    
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}

/* You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. 
Continue the same until the end of the linked list.
To put it in other words, in the given linked list, 
you need to delete N nodes after every M nodes.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2

Sample Output 1 :
1 2 5 6
**************************
Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3

Sample Output 2 :
1 2 6 7
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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head == NULL || M == 0) {
        return NULL;
    }
    if(N == 0) {
        return head;
    }
    
    Node *t2 = NULL;
    Node *temp = head;
    
    while(temp!=NULL) {
    	int stay = 0;
        int remove = 0;
        while(temp!=NULL&&stay<M) {
            if(t2==NULL) {
                t2 = temp;
            }
            else {
                t2 -> next = temp;
                t2 = t2 -> next;
            }
            stay++;
            temp = temp -> next;
        }
        while(temp!=NULL&&remove<N) {
            Node *removednode = temp;
            delete temp;
            temp = temp -> next;
            remove++;
        }
    }
    
    if(t2!=NULL) {
        t2 -> next = NULL;
    }
     return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}

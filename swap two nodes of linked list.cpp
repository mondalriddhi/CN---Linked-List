/*  You have been given a singly linked list of integers along with two integers, 'i,' and 'j.'
 Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
***************************
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
  	if(i==j) {
        return head;
    }
    Node *currNode = head;
    Node *prev = NULL;
    Node *firstNode = NULL;
    Node *secNode = NULL;
    Node *firstNodeprev = NULL;
    Node *secNodeprev = NULL;
    int pos = 0;
    while(currNode!=NULL) {
        if(pos==i) {
            firstNodeprev = prev;
            firstNode = currNode;
        }
        else if(pos==j) {
            secNodeprev = prev;
            secNode = currNode;
        }
        prev = currNode;
        currNode = currNode -> next;
        pos++;
    }
    
    if(firstNodeprev!=NULL) {
        firstNodeprev -> next = secNode;
    }
    else {
        head = secNode;
    }

    if(secNodeprev!=NULL) {
        secNodeprev -> next = firstNode;
    }
    else {
        head = firstNode;
    }
    
    Node *currFirstnode = secNode -> next;
    secNode -> next = firstNode -> next;
    firstNode -> next = currFirstnode;
    
    return head;    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}

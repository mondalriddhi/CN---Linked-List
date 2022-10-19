/*  Given a singly linked list of integers and an integer n, 
     find and return the index for the first occurrence of 'n' in the linked list.
	  -1 otherwise.
Follow a recursive approach to solve this.
Note :
Assume that the Indexing for the linked list always starts from 0.

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
100
Sample Output 1 :
-1
***********************
Sample Input 2 :
2
10 20010 30 400 600 -1
20010
100 200 300 400 9000 -34 -1
-34
Sample Output 2 :
1
5
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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int findNodeRec(Node *head, int n)
{
	//Write your code here
    if(head==NULL) {
        return -1;
    }
	else if(head -> data == n) {
        return 0;
    }
    
    int ans = findNodeRec(head -> next, n);
    if(ans == -1) {
        return -1;
    }
    
    return ans + 1;
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}

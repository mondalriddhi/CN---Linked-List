/*You have been given a singly linked list of integers.
 Write a function that returns the index/position of integer data denoted by 'N' (if it exists). 
 Return -1 otherwise.
 Note :
Assume that the Indexing for the singly linked list always starts from 0.

Sample Input 2 :
2
1 -1
2
3 4 5 2 6 1 9 -1
6

Sample Output 2 :
-1
4
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

int findNode(Node *head, int n){
    // Write your code here.
    int count = 0;
    Node *temp = head;
    if(head==NULL) {
        return -1;
    }
    while(temp!=NULL){
        if(temp -> data != n) {
        	count++;
        	temp = temp -> next;
    	}	 
    
    	else if(temp -> data == n) {
        	return count;
    	}
    }
    
    return -1;
    
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
		cout << findNode(head, val) << endl;
	}
}

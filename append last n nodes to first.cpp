/*You have been given a singly linked list of integers along with an integer 'N'.
 Write a function to append the last 'N' nodes towards the front of the singly linked list and
  returns the new head to the list.
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head==NULL||n==0){
        return head;
    }
    int count = 0;
    int lenll = length(head);
    Node *firstad = head;
    Node *temp = head;
    while(temp!=NULL&&count<lenll-n-1) {
        count++;
        temp = temp -> next;
    }
    Node *pos = temp -> next;
    
    head = pos;

    while(pos -> next!=NULL) {
        pos = pos -> next;
    }
    pos -> next = firstad;
    temp -> next = NULL;
    return head;
    
}
  /*    Coding Ninja approach
  time complexity = O(n)
  space complexity= O(1)
  
Node *appendLastNToFirst(Node *head, int n) {
	if(head==NULL||n==0){
		return head;
	}
	Node *fast = head;
	Node *slow = head;
	Node *initialhead = head;
	
	for(int i=0;i<n;i++){
		fast = temp -> next;
	}
	
	while(fast -> next!= NULL){
		slow = slow -> next;
		fast =fast -> next;
	}
	
	Node *temp = slow -> next;
	slow -> next = NULL;
	fast -> next = initialhead;
	head = temp;
	
	return head;

}
*/
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

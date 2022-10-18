/*
Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10 
*********************** 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90 
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

Node* midpoint(Node *head) {
    if(head==NULL||head->next==NULL) {
        return head;
    }
    Node *temp = head;
    Node *slow = head;
	
    Node *fast = head->next;
    while(fast!=NULL&&fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    
    Node *h = NULL;
    Node *t = NULL;
    
    if(head1==NULL&&head2==NULL) {
    	return h;    
    }
    if(head1!=NULL&&head2==NULL) {
        return head1;
    }
    if(head2!=NULL&&head1==NULL) {
        return head2;
    }
    
    if (head1 -> data > head2 -> data) {
        h = head2;
        t = head2;
        head2 = head2 -> next;
    }
    else {
        h = head1;
        t = head1;
        head1 = head1 -> next;
    }
    while(head1!=NULL&&head2!=NULL) {
        if(head1 -> data > head2 -> data) {
            t -> next = head2;
            t = t -> next;
            head2 = head2 -> next;
        }
        else {
            t -> next = head1;
            t = t -> next;
            head1 = head1 -> next;
        }
    }
    
    while(head1!=NULL) {
        t -> next = head1;
        t = t -> next;
        head1 = head1 -> next;
    }
    
    while(head2!=NULL) {
        t -> next = head2;
        t = t -> next;
        head2 = head2 -> next;
    }
    t -> next = NULL;
    return h;
}

   


Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL||head->next==NULL) {
        return head;
    }
    Node *temp = head;
    Node *mid = midpoint(temp);
    Node *rightside = mid -> next;
    mid -> next = NULL;
    Node *left = mergeSort(temp);
    Node *right = mergeSort(rightside);
    temp = mergeTwoSortedLinkedLists(left, right);
    return temp;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}















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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}

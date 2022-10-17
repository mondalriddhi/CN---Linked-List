#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}


Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}

Node* insertNodeRecursive(Node *head, int i, int data) {
	// Write your code here
    if(head==0) {
        return head;
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    if(i==0) {
    	newNode -> next = head;
        head = newNode;
        return head;
    }
 
    
	Node *recnode = insertNodeRecursive(head -> next, i-1, data);
    temp -> next = recnode;
    return head;
}

Node *deleteNode(Node *head, int pos)   //pos starts from 0...(index number of linked list)
{
   /* int lenll = length(head);
    if (lenll<=pos){                       
        return head;
    }*/
    // Write your code here.
    if(head==NULL) {
        return head;
    }
    Node *temp = head;
    int count = 0;
    if(pos == 0) {                      //deleting first node
        Node *a = temp -> next;        //   can also be replaced by
		head = a;                      //    writing just
        return head;                   //    return head -> next;
    }
     while(temp!=NULL && count<pos-1) {
         temp = temp -> next;
         count++;
     }
    if (temp==NULL||temp -> next==NULL) {        //if pos is greater than list length 
        return head;                             //pos doesnt even exist in list 
    }
    if(temp!=NULL) {
        Node *a=temp -> next;
        Node *b=a -> next;
        temp -> next = b;
        delete a;
        //return head;
    }
    return head;
}


Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head==NULL) {
        return head;
    }
    Node *temp = head;
    if(pos==0) {
        head = head -> next;
        delete temp;
        return head;
    }
    
    Node *recnode = deleteNodeRec(head ->next, pos-1);
    temp -> next = recnode;
    return head;
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

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

int main() {

	Node *head = takeInput_Better();
	print(head);
	int i, data;
	cin >> i >> data;
	head = insertNode(head, i, data);
	print(head);


}


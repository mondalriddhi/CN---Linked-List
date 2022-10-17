/*You have been given a head to a singly linked list of integers.
 Write a function check to whether the list given is a 'Palindrome' or not.
 
Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true

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


Node* reverse(Node *head) {
    if(head==NULL||head -> next==NULL) {
        return head;
    }
	Node *dummy = NULL;
    Node *temp = head;
    Node *nextNode = NULL;   
    while(temp != NULL) {
        nextNode = temp -> next;
        temp -> next = dummy;
        dummy = temp;
        temp = nextNode;
    }
    return dummy;
}


bool isPalindrome(Node *head)
{
    if(head==NULL||head->next==NULL){
        return true;
    }
    //finding middle of linked list
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL&&fast -> next!=NULL) {   //for even number  of nodes middle= (n/2)+1
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
   
    Node *oddSlow = slow;
    Node *revSlow = reverse(slow);
    //oddSlow -> next = NULL;   //for odd number of nodes

    
    Node *tempm = head;
    while(revSlow!=NULL && tempm!= NULL) {
        if(tempm->data!=revSlow->data) {
            return false;
        }
        tempm = tempm -> next;
        revSlow = revSlow -> next;
    }
    return true;
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}

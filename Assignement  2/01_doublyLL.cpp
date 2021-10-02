#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int data)
    {
        this->next = NULL;
        this->previous = NULL;
        this->data = data;
    }
};

void traverseLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ,";
        head = head->next;
    }
}

void traverseBackward(Node *back)
{
    while (back != NULL)
    {
        cout << back->data << " ,";
        back = back->previous;
    }
}

void insertAtBegining(Node *&head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        head = node;
    }
    else
    {
    node->next = head;
    head->previous = node;
    head = node;
    }
}

void insertAtEnd(Node *last, int data)
{
    Node *node = new Node(data);
    last->next = node;
    node->previous = last;
}

Node *lastNode(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

void insertionAtMid(Node *head, int elem)
{
    Node *temp = new Node(elem);

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    temp->next = slow->next;
    temp->previous = slow;
    slow->next->previous = temp;
    slow->next = temp;
}

void insertAfterNode(Node *node,int data){
    Node *temp = new Node(data);
    temp->previous = node;
    temp->next = node->next;
    node->next->previous = temp;
    node->next = temp;
}
void Afternthnode(int data,int npos,Node *temp)
{
    while(temp->next!=NULL && npos>1)
    {
        temp=temp->next;
        npos--;
    }
    Node *newnode=new Node(data);
    
    newnode->next=temp->next;
    temp->next=newnode;
}

int main()
{

    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(45);
    Node *third = new Node(65);

    head->next = first;
    first->next = second;
    first->previous = head;

    second->next = third;
    second->previous = first;

    third->previous = second;

    traverseLinkedList(head);
    // cout<<"Back Wards=> " << endl;
    // traverseBackward(third);

    cout << "\nAfter Insertion => " << endl;
    // insertAtBegining(head, 50);
    // insertAtEnd(lastNode(head), 33);
    // insertionAtMid(head,99);
   // insertAfterNode(first,33);
    Afternthnode(21,2,head);
    traverseLinkedList(head);
    
    
    return 0;
}

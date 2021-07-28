#include <iostream>
using namespace std;

class circularList
{
    struct Node
    {
        int data;
        struct Node *link;
    };

    Node *newNode(int data)
    {
        Node *temp = new Node;
        temp->link = temp;
        temp->data = data;
        return temp;
    }
    Node *head;
    Node *tail;
    
    
public:
    void advanceN(int n)
    {

        head = newNode(1);
        tail = head;
        for (int i = 2; i <= n; i++)
        {
            tail->link = newNode(i);
            tail = tail->link;
        }
        tail->link = head;
    }

    void deleteThis(int x)
    {
        Node *ptr1 = head;
        Node *ptr2 = head;
        
        while (ptr1->link != ptr1)
        {
            int count = 1;
            
            while (count != x)
            {
                ptr2 = ptr1;
                ptr1 = ptr1->link;
                count++;
            };

            cout<<"Node eliminated: "<< ptr1->data <<endl;
            ptr2->link = ptr1->link;
            ptr1 = ptr2->link;
        };
        cout<<"Last node:"<< ptr1->data <<endl;
    };
    
};
int main()
{
    int n;
    int x;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>n;
    cout<<"Enter the number the list should skip at each interval:"<<endl;
    cin>>x;
    circularList c;
    c.advanceN(n);
    c.deleteThis(x);
}
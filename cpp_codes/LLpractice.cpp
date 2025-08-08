#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void InsertatLast(int value,Node* head,Node* tail) // Function for creating a LinkedList
{
    Node *newnode = new Node(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}
Node* convertArrtoLL(vector<int> &arr){  //Function for converting an array to a LinkedList
    Node* head=new Node(arr[0]);
    Node *mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* add2LL(Node *l1,Node* l2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* newNode=new Node(sum%10);
        temp->next=newNode;
        temp=newNode;
    }
    return dummyNode->next;
    //points to head
}
Node* oddEvenIndices(Node* headd){
    vector<int> a;
    Node* temp=headd;
    while(temp!=NULL && temp->next!=NULL){
        a.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        a.push_back(temp->data);
    }
    temp=headd->next;
    while(temp!=NULL && temp->next!=NULL){
        a.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        a.push_back(temp->data);
    }
    temp=headd;
    int i=0;
    while(temp!=NULL){
        temp->data=a[i];
        temp=temp->next;
        i++;
    }
    return headd;
}
int main(){
    vector <int> arr1={3,5};
    Node* head1=convertArrtoLL(arr1);
    print(head1);
    cout<<endl;
    vector <int> arr2={4,5,9,9};
    Node* head2=convertArrtoLL(arr2);
    print(head2);
    cout<<endl;
    Node * head=add2LL(head1,head2);
    print(head);
    cout<<endl;
    vector<int> array={1,2,3,4,5,6,7};
    Node* headd=convertArrtoLL(array);
    Node* headd2=oddEvenIndices(headd);
    print(headd2);

    

}
#include <iostream>

using namespace std;
class binary_tree
{
protected:
    class node{
    public:
        int data;
        node *left;
        node *right;
    };
    node *root;
    class list{
    public:
        int value;
        list *prev;
        list *next;
    };
    list *head;
    list *tail;
    list *cursor;
public:
    binary_tree();
    void insert(int x);
    void basePrint(node *bp);
    void printTree();
    void insertl(int l);
    void treetolist();
    void baseTTL(node *tr);
    void printList();
};//the class includes both tree and list

int main()
{
    binary_tree t;
    t.insert(7);
    t.insert(2);
    t.insert(3);
    t.insert(1);
    t.insert(4);
    t.insert(9);
    t.insert(5);
    t.insert(8);
    t.insert(6);

    t.printTree();//prints tree in postorder.
    t.treetolist();//inserts tree to list.
    t.printList();//prints values in list.
    return 0;
}

void binary_tree::insertl(int l)
{
    list* b = new list;
    b->value = l;
    b->next = NULL;
    b->prev = NULL;
    if(head==NULL && tail==NULL)
    {
        head = b;
        tail = b;
        cursor = b;
    }
    else
    {
        b->prev=cursor;
        cursor->next = b;
        cursor = b;
        tail = cursor;
    }
 }//function to insert values into list.

void binary_tree::baseTTL(node* tr)
{
    if(tr->right!=NULL)
    {
        baseTTL(tr->right);
    }
    insertl(tr->data);
    if(tr->left!=NULL)
    {
        baseTTL(tr->left);
    }
}//recursively traverses the tree with inorder notation and inserts the values into the list.
void binary_tree::treetolist()
{
    baseTTL(root);
}//passes root into the baseTTL function

binary_tree::binary_tree()
{
    root = NULL;
    head = NULL;
    tail = NULL;
    cursor = NULL;
}
//initializes the pointers for the tree and the list

void binary_tree::insert(int x)
{
    node* tmp = new node;
    node* parent;
    node* current = NULL;
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    parent = NULL;
    if(root == NULL)
    {
        root = tmp;
    }
    else
    {
        current = root;
        while(current!=NULL)
        {
            parent = current;
            if(tmp->data > current->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }

        if(tmp->data < parent->data)
        {
           parent->left = tmp;
        }
        else
        {
           parent->right = tmp;
        }
    }
}
//inserts into tree
void binary_tree::basePrint(node * bp){
    if(bp==NULL){
        cout<<" ";
    }
    else
    {
        basePrint(bp->left);
        cout<<" "<<bp->data<<" ";
        basePrint(bp->right);
        cout<<" ";
    }
}
//prints data in postorder
void binary_tree::printTree(){
    basePrint(root);
}//passes root into basePrint

void binary_tree::printList()
{
    list *tmp;
    tmp = head;
    while(tmp!=NULL)
    {
        cout<<" "<<tmp->value<<", ";
        tmp = tmp->next;
    }
}
//prints list


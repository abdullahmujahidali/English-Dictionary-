#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
   int key;
   string data;
   Node* next;
};

class singleSortedlinkedlist{
   private:
       Node *head;
   public:
       singleSortedlinkedlist():head(NULL){
          
       }
       Node *newNode(int key, string new_data) {
           /* allocate node */
           Node* new_node =new Node();
  
           /* put in the data */
           new_node->data = new_data;
           new_node->key = key;
           new_node->next = NULL;

           return new_node;
       }
      
       /* function to insert a new_node in a list. Note that this
       function expects a pointer to head_ref as this can modify the
       head of the input linked list (similar to push())*/
       void sortedInsert(int key, string data)
       {
           Node* current;
           /* Special case for the head end */
           Node *new_node = this->newNode(key, data);
           if (this->head == NULL || this->head->key >= new_node->key)
           {
               new_node->next = this->head;
               this->head = new_node;
           }
           else
           {
               /* Locate the node before the point of insertion */
               current = this->head;
               while (current->next!=NULL &&
                   current->next->key < new_node->key)
               {
                   current = current->next;
               }
               new_node->next = current->next;
               current->next = new_node;
           }
       }
      
       /* Function to print linked list */
       void printList()
       {
           Node *temp = this->head;
           while(temp != NULL)
           {
               cout<<temp->key<<" : "<<temp->data<<", ";
               temp = temp->next;
           }
       }
      
       /* Function to delete a node from linked list */
       void deleteNode(int key){
           Node *temp = this->head;
           Node *prev;
           if(temp->key == key){
               this->head = this->head->next;
               return;
           }
           prev = temp;
           temp = temp->next;
          
           while(temp != NULL){
               if(temp->key == key){
                   prev->next = temp->next;
                   return;
               }
               prev = temp;
               temp = temp->next;
           }
       }
};

/* Driver program to test count function*/
int main()
{
   /* Start with the empty list */
  
   singleSortedlinkedlist sl;
   sl.sortedInsert(1,"hello");
   sl.sortedInsert(5,"bye");
   sl.sortedInsert(2,"namaste");
   sl.sortedInsert(6,"go");
   sl.sortedInsert(3,"away");
  
   cout<<"before deletion."<<endl;
   sl.printList();
   sl.deleteNode(3);
   cout<<"\nafter deletion."<<endl;
   sl.printList();
  

   return 0;
}
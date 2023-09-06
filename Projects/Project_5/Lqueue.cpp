#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
   public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  // Required
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
  // Required
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue<T>& operator= (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  // Required
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  // Required (used only for testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front
  // Required
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Required
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  // Required
  void Clear();
  // Name: At
  // Precondition: Existing Lqueue
  // Postcondition: Returns object from Lqueue at a specific location
  // Desc: Iterates to node x and returns data from Lqueue
  // Required
  T At (int x);
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Lqueue Class Here***********
//**********All Functions Are Required Even If Not Used for Trivia**************

template <class T>
Lqueue<T>::Lqueue(){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
}

template <class T>
Lqueue<T>::~Lqueue(){
   Clear();
}

template <class T>
Lqueue<T>::Lqueue(const Lqueue& originalLinkedList){
   m_size = 0;
   m_head = nullptr;
   m_tail = nullptr;
   //if size of linked list is 0, default constructor will make
   //a copy of a 0 sized linked list
   if(originalLinkedList.m_head == nullptr){
      m_head = nullptr;
      m_tail = nullptr;
      m_size = 0;

   //if size is greater than 0, copy each node into
   //linkedListCopy pointer
   }else{

      //temp will interate through original list
      Node<T>* temp = originalLinkedList.m_head;

      //copyingNode will copy data into the new list
      //Node<T>* copyingNode = nullptr;

      //data is the data that will be copied over
      T data;

      while(temp != nullptr){
         data = temp -> GetData();
         //copyingNode = new Node(data);

         //if linkedListCopy is empty, set the first node as
         //m_head
         Push(data);

         temp = temp -> GetNext();
         //copyingNode = nullptr;


      }

   }
}

template <class T>
Lqueue<T> & Lqueue<T>::operator= (Lqueue& originalLinkedList){
   //If the linked list is empty, clear it so it actually
   //is equal to nothing and not random floating thingies

   if(m_size != 0){
      Node<T>* curr = m_head;
      Node<T>* prev = m_head;

      //Time to iterate!
      //curr is one step ahead and
      //the previous node is deleted
      while(curr != nullptr){
         curr = curr -> GetNext();
         delete prev;
         prev = curr;
      }
      m_head = nullptr;
      m_tail = nullptr;
      curr = nullptr;
      prev = nullptr;
   }

   //Now, we can copy the originalLinkedList
   //data gets data from originalLinkedList
   T data;
   Node<T>* temp = originalLinkedList.m_head;
   //Node<T>* copyingNode = nullptr;

   while(temp != nullptr){
      data = temp -> GetData();
      //copyingNode = new Node(data);
      //if linkedListCopy is empty, set the first node as
      //m_head
      Push(data);
      temp = temp -> GetNext();

   }

   return *this;
   
}

template <class T>
void Lqueue<T>::Push(const T& data){
   //previous m_tail points to new node
   //m_tail then iterates to new node
   //finally, increment size
   Node<T>* temp = new Node(data);

   if(m_head == nullptr){
      m_head = temp;
      m_tail = temp;
      m_size += 1;
   }else{
      m_tail -> SetNext(temp);
      m_tail = temp;
      m_size += 1;
   }

   temp = nullptr;
}

template <class T>
T Lqueue<T>::Pop(){
   T data;
   data = m_head -> GetData();
   //if only one element in the list
   if(m_head == m_tail){
      data = m_head -> GetData();
      m_tail = m_tail -> GetNext();
      delete m_head;
      m_head = nullptr;
      m_size -= 1;

   //if you have more than one element in the list
   }else{
      Node<T>* prev = m_head;
      m_head = m_head -> GetNext();
      delete prev;
      m_size -= 1;
      prev = nullptr;
   }

   return data;
}

template <class T>
void Lqueue<T>::Display(){
   int index = 1;
   Node<T>* curr = m_head;

   while(curr != nullptr){
      cout << index << ". " << (curr -> GetData()) << endl;
      index += 1;
      curr = curr -> GetNext();
   }
}

template <class T>
T Lqueue<T>::Front(){
   if(m_head != nullptr){
      return m_head -> GetData();
   }
}


template <class T>
bool Lqueue<T>::IsEmpty(){
   if(m_size == 0){
      return true;
   }else{
      return false;
   }
}

template <class T>
int Lqueue<T>::GetSize(){
   return m_size;
}

template <class T>
int Lqueue<T>::Find(T& data){
   int index = 0;
   Node<T>* curr = m_head;

   while(curr != nullptr){
      if((curr -> GetData()) == data){
         return index;
      }else{
         curr = curr -> GetNext();
         index += 1;
      }
   }

   return -1;
}

template <class T>
void Lqueue<T>::Swap(int index){
   Node<T>* curr = m_head;
   Node<T>* prev = m_head;
   Node<T>* twoBefore = m_head;

   if(m_size < 2){
      cout << "Can not swap 2 nodes if there are less than 2 nodes" << endl;   
   }else if(m_size >= 2){
      //Set curr to index
      for(int i = 0; i < index; i++){
         curr = curr -> GetNext();
      }
      //Set prev to one behind index
      for(int j = 0; j < (index - 1); j++){
         prev = prev -> GetNext();
      }

      //point prev m_next to the one after curr
      prev -> GetNext() = curr -> GetNext();

      //if previous was m_head, set m_head to
      //curr since curr will point to previous
      if(prev == m_head){
         m_head = curr;
      }

      //point curr m_next to prev
      curr -> GetNext() = prev;

      //if curr is m_tail, point it to prev since that
      //is the new last element
      if(curr == m_tail){
         m_tail = prev;
      }

      //now, iterate through the list
      //if m_next = prev, then make that
      //m_next point to curr
      Node<T>* temp = m_head;
      while(temp != nullptr){
         if(temp -> GetNext() == prev){
            temp -> GetNext() = curr;
         }else{
            temp = temp -> GetNext();
         }
      }


   }
}

template <class T>
void Lqueue<T>::Clear(){
   Node<T>* curr = m_head;
   Node<T>* toDelete = m_head;

   while(curr != nullptr){
      curr = curr -> GetNext();
      delete toDelete;
      toDelete = curr;
   }

   curr = toDelete = m_head = m_tail = nullptr;
}

template <class T>
T Lqueue<T>::At(int index){
   if(index >= 0 and index < m_size){
      Node<T>* curr = m_head;
      for(int i = 0; i < index; i++){
         curr = curr -> GetNext();
      }

      return curr -> GetData();

   }
}

#endif

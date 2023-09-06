/*
Author: Alfonso Sebastian Apelacio Martinez
Filename: Lstack.cpp
Date: 12/07/2022
Description: Deals with linked list actions and Rule of Three
*/

#ifndef LSTACK_CPP
#define LSTACK_CPP
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
  T m_data; //Templated data for node
  Node<T>* m_next; //Templated node pointer to next node
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
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
class Lstack {
 public:
  // Name: Lstack() (Linked List Stack) - Default Constructor
  // Desc: Used to build a new templated stack (as a linked list) m_head = top
  // Preconditions: None
  // Postconditions: Creates a new lstack where m_head points to nullptr and m_size = 0
  // Required
  Lstack();
  // Name: ~Lstack() - Destructor
  // Desc: Used to destruct a Lstack
  // Preconditions: There is an existing lstack with at least one node
  // Postconditions: An lstack is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks. (Allowed to use Clear in this function)
  // Required
 ~Lstack();
  // Name: Lstack (Copy Constructor)
  // Preconditions: Creates a copy of existing LStack
  //                Requires an existing Lstack
  // Hint: Make sure that the copy is not inverted
  // Postconditions: Copy of existing Lstack
  // Required
  Lstack(const Lstack&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Requires two Lstacks holding the same type of data
  //                After running, both stacks are identical with no memory loss
  //                Requires an existing Lstack
  // Postconditions: Two identical Lstack
  // Hint: Make sure that the destination Lstack has the same data in the same order as source
  // Required
  Lstack<T>& operator= (Lstack&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires an existing Lstack
  // Postconditions: Adds a new node to the top of the lstack.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Requires an existing Lstack with at least one node 
  // Postconditions: Removes top node in the lstack.
  // Assume that the Lstack has at least one node (Will check prior to call)
  // Required
  void Pop();
  // Name: Display
  // Preconditions: Outputs the lstack.
  // Postconditions: Displays the data in each node of lstack
  // Required (used only for testing lstack_test)
  void Display();
  // Name: Top
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns whatever data is on top
  // Required
  T Top();
  // Name: IsEmpty
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns true if the Lstack is empty else false.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Clear
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Removes all nodes in Lstack
  // Required
  void Clear();
  // Name: At(int)
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Returns the data at a specific index;
  //                 Index will be checked prior to call (assume int is valid)
  // Required
  T At (int x);
private:
  Node <T> *m_head; //Node pointer for the head
  int m_size; //Number of nodes in stack
};

//**********Implement Lstack Class Here***********
//**********All Functions Are Required Even If Not Used for Processor**************

template <class T>
Lstack<T>::Lstack(){
   m_head = nullptr;
   m_size = 0;
}

//destructor
template <class T>
Lstack<T>::~Lstack(){
   Clear();
   delete m_head;
   m_head = nullptr;
}

//copy constructor
template <class T>
Lstack<T>::Lstack(const Lstack& originalStack){
   m_size = 0;
   m_head = nullptr;
   Node<T>* newNode = nullptr;

   //if the original stack is size 0, keep the 0 sized
   //linked list. Below codes if the size is greater than 0
   if(originalStack.m_size > 0){
      //set the node pointer to the start of the linked list
      Node<T>* nodePointer = originalStack.m_head;
      Node<T>* current = nullptr;

      //below is a variable that will copy the data over to the new linked list
      T data;

      while(nodePointer != nullptr){
         //grabs the data
         data = nodePointer -> GetData();

         //create node with data and add to the end of the list
         newNode = new Node(data);

         //if m_head = nullptr (first on the list), then set newNode as m_head
         if(m_head == nullptr){
            m_head = newNode;
            current = newNode;
         }else{
            current -> SetNext(newNode);
            current = newNode;
         }

         //increment size
         m_size += 1;

         //go to next node for copying
         nodePointer = nodePointer -> GetNext();
         newNode = nullptr;
      }
      current = nullptr;
   }
}

//overloaded operator
template <class T>
Lstack<T>& Lstack<T>::operator=(Lstack& stack){
   if(this != &stack){
      Clear(); //delete everything first

      //now we need to make a copy of stack
      //basically copy the copy constructor
      //below initializes some variables
      Node<T>* newNode = nullptr;
      Node<T>* nodePointer = stack.m_head;
      Node<T>* current = nullptr;
      T data;

      //now iterate while nodePointer is not at the end
      while(nodePointer != nullptr){
         data = nodePointer -> GetData(); //Get data from stack node
         newNode = new Node(data); //makes a new node to use in our stack
         if(m_head == nullptr){
            m_head = newNode;
            current = newNode;
         }else{
            current -> SetNext(newNode);
            current = newNode;
         }

         m_size += 1;
         nodePointer = nodePointer -> GetNext();
         newNode = nullptr;
      }
      current = nullptr;
   }
   return *this;
}

template <class T>
void Lstack<T>::Push(const T& data){ //Pushes to the beginning of the linked list
   Node<T>* newNode = new Node(data);

   //If there is no list, set m_head and m_tail = newNode
   if(m_head == nullptr){
      m_head = newNode;
   }else{
      //sets m_head as the new node. previous m_head is now second on the linked list
      newNode -> SetNext(m_head);
      m_head = newNode;
   }

   newNode = nullptr;
   m_size += 1;
}

template <class T>
void Lstack<T>::Pop(){
   if(m_size > 1){
      //sets new m_head to second item in linked list
      Node<T>* deleteFirst = m_head;
      m_head = m_head -> GetNext();

      //now delete the first thing
      delete deleteFirst;
      deleteFirst = nullptr;
   }else{
      delete m_head;
      m_head = nullptr;
   }

   m_size -= 1;
}

template <class T>
void Lstack<T>::Display(){
   Node<T>* toDisplay = m_head;
   while(toDisplay != nullptr){
      cout << toDisplay -> GetData() << ", ";
      toDisplay = toDisplay -> GetNext();
   }
   cout << endl;
}

template <class T>
T Lstack<T>::Top(){
   return m_head -> GetData();
}

template <class T>
bool Lstack<T>::IsEmpty(){
   if(m_size == 0){
      return true;
   }else{
      return false;
   }
}

template <class T>
int Lstack<T>::GetSize(){
   return m_size;
}

template <class T>
int Lstack<T>::Find(T& data){
   Node<T>* findData = m_head;
   int index = 0;

   //iterate. If data matches, found = true. Stop when found or when list is done
   while(findData != nullptr){
      if((findData -> GetData()) == data){
         return index;
      }
      index += 1;
      findData = findData -> GetNext();
   }

   return (-1);

}

template <class T>
void Lstack<T>::Clear(){
   Node<T>* current = m_head;
   Node<T>* previous = nullptr;
   while(current != nullptr){
      previous = current;
      current = current -> GetNext();
      delete previous;
      previous = nullptr;
   }

   m_head = nullptr;
   m_size = 0;
}

template <class T>
T Lstack<T>::At(int x){
   Node<T>* findData = m_head;
   for(int i = 0; i < x; i++){
      findData = findData -> GetNext();
   }

   return findData -> GetData();
}



#endif

#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>
#include "NullNodeException.hpp"

// Class template for a singly linked list.
// Note: In a class template definition, C++ will assume
//   any reference to the class is templated.
//   So, inside LList writing LList means LList<T>
template <class T>
class LList
{
private:
   // Structure containing the data and
   // pointers to the next node.
   struct Node
   {
      T data;
      Node * next;

      Node(const T & theData, Node * nextNode = nullptr)
	 : data{theData}, next{nextNode}
      {}
   };

   Node * head; // pointer to head of list
   Node * cur;  // pointer to current position in list
   Node * prev; // pointer to previous position in list

public:
   LList() : head{}, cur{}, prev{}
   {}

   ~LList()
   {
      clear();
   }

   // Test if current position is null.
   bool isCurNull() const
   {
      return cur == nullptr;
   }

   // Test if there is a next element.
   bool hasNext() const
   {
      return !isCurNull() && cur->next != nullptr;
   }

   // Move to the head of the list.
   // Return a reference to the invoking object.
   LList & toHead()
   {
      cur = head;
      prev = nullptr;
      return *this;
   }

   // Move to the next element.
   // Return a reference to the invoking object.
   LList & toNext();

   // Get the data at the current position.
   // Throw a NullNodeException if the current position is null.
   T getData() const;

   // Set the data at the current position.
   // Throw a NullNodeException if the current position is null.
   // Return a reference to the invoking object.
   LList & setData(const T & value);

   // Insert a new element before the current position
   // and move to this position.
   // If the current position is null and the list is not empty,
   // then the new element will not be inserted.
   // Return a reference to the invoking object.
   LList & insertBefore(const T & data);
   
   // Insert a new element after the current position
   // and move to this position.
   // If the current position is null and the list is not empty,
   // then the new element will not be inserted.
   // Return a reference to the invoking object.
   LList & insertAfter(const T & data);
   
   // Remove the element at the current position
   // and move to the next position.
   // Return a reference to the invoking object.
   LList & remove();

   // Remove all elements in this list.
   // Return a reference to the invoking object.
   LList & clear();

   // Test if the list is empty.
   bool isEmpty() const
   {
      return head == nullptr;
   }

private:
   std::ostream & print(std::ostream & os) const;

   // Allows us to print an LList object to a std::ostream object.
   // Note: friend functions are not members of classes.
   friend std::ostream & operator<<(std::ostream & os, const LList & l)
   {
      return l.print(os);
   }
};

#endif

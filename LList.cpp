#ifndef LLIST_CPP
#define LLIST_CPP

#include "LList.hpp"

// Move to the next element.
// Return a reference to the invoking object.
template <class T>
LList<T> & LList<T>::toNext()
{
   if (!isCurNull())
   {
      prev = cur;
      cur = cur->next;
   }

   return *this;
}

// Get the data at the current position.
// Throw a NullNodeException if the current position is null.
template <class T>
T LList<T>::getData() const
{
   if (isCurNull()) throw NullNodeException{};

   return cur->data;
}

// Set the data at the current position.
// Throw a NullNodeException if the current position is null.
// Return a reference to the invoking object.
template <class T>
LList<T> & LList<T>::setData(const T & value)
{
   if (isCurNull()) throw NullNodeException{};

   cur->data = value;
   return *this;
}

// Insert a new element before the current position
// and move to this position.
// If the current position is null and the list is not empty,
// then the new element will not be inserted.
// Return a reference to the invoking object.
template <class T>
LList<T> & LList<T>::insertBefore(const T & data)
{  
   if (isCurNull() && !isEmpty()) return *this;

   // At this point either
   //   both isCurNull() and isEmpty() are true, OR
   //   both isCurNull() and isEmpty() are false.

   Node * newNode = new Node{data, cur};

   if (cur == head) // if cur is at head or list is empty
      head = newNode;
   else // there is a previous node
      prev->next = newNode;

   cur = newNode;
   return *this;
}

// Insert a new element after the current position
// and move to this position.
// If the current position is null and the list is not empty,
// then the new element will not be inserted.
// Return a reference to the invoking object.
template <class T>
LList<T> & LList<T>::insertAfter(const T & data)
{
   if (isCurNull() && !isEmpty()) return *this;

   // At this point either
   //   both isCurNull() and isEmpty() are true, OR
   //   both isCurNull() and isEmpty() are false.

   Node * newNode = new Node{data};

   if (isEmpty())
   {
      head = newNode;
   }
   else // isCurNull() is false
   {
      newNode->next = cur->next;
      cur->next = newNode;
   }

   prev = cur;
   cur = newNode;
   return *this;
}

// Remove the element at the current position
// and move to the next position.
// Return a reference to the invoking object.
template <class T>
LList<T> & LList<T>::remove()
{
   if (!isCurNull())
   {
      Node * delNode = cur; // node to delete
      cur = cur->next;
      
      if (prev != nullptr) prev->next = cur;
      if (head == delNode) head = cur;

      delete delNode;
      delNode = nullptr;
   }

   return *this;
}

// Remove all elements in this list.
// Return a reference to the invoking object.
template <class T>
LList<T> & LList<T>::clear()
{
   toHead();

   while (!isCurNull()) remove();

   return *this;
}

// Print this list to an std::ostream object
template <class T>
std::ostream & LList<T>::print(std::ostream & os) const
{
   os << "[";

   if (!isEmpty())
   {
      Node * p = head;

      while (true)
      {
	 if (p == cur) os << "*";

	 os << p->data;
	 p = p->next;

	 if (p == nullptr) break;

	 os << ", ";
      }
   }

   return os << "]";
}

#endif

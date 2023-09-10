// INSTRUCTION:
// It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//   Highly recommended to copy HW3P1-help as PURPOSE of each function.
//   Add sufficient comments to your code body to describe what it does.
//       - Make sure all if-then-else are commented describing which case it is
//       - Make sure all local variables are described fully with their purposes

// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

// ====================================================
// Your name: Clément Nicolas Denis Muth
// Complier: g++
// File type: linkedList.cpp implementation file
//=====================================================

#include <iostream>
#include "linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList()
{
    Node *temp = _front;

    while (_front != nullptr) {
        temp = _front;
        _front = _front->next;
        delete temp;
    }
    delete _front;
    delete _rear;
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const
{
    return _count == 0;
}

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const
{
    int count = 0;
    Node *temp = _front;

    while (temp != nullptr) {
        temp = _front->next;
        count++;
    }
    return count;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString()
{
    string str = "[";
    Node *ptr = _front;

    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll()
{
    cout << toString() << endl;
}

// TODO: Add comments
void LinkedList::addRear(T val)
{
    Node *new_node = new Node(val);

    if (_front == nullptr) {
        _front = new_node;
        _rear = new_node;
    }
    else {
        _rear->next = new_node;
        _rear = new_node;
    }
    _count++;
}

// TODO: Add comments
void LinkedList::addFront(T val)
{
    Node *newNode = new Node(val);

    newNode->next = _front;
    _front = newNode;
    _count++;
}

/**
 * @brief Delete the first node of the list
 * @param oldNum the value of the deleted node
 * @return true if the node was removed or false otherwise
 */
bool LinkedList::deleteFront(T &OldNum)
{
    Node *ptr = _front;

    if (_front == nullptr) return false;
    OldNum = _front->val;
    if (_front == _rear) _front = _rear = nullptr;
    else ptr = _front->next;
    _count--;
    delete _front;
    _front = ptr;
    return true;
}

/**
 * @brief Delete the latest node of the list
 * @param oldNum the value of the deleted node
 * @return true if the node was removed or false otherwise
 */
bool LinkedList::deleteRear(T &OldNum)
{
    Node *ptr = _front;

    if (_front == nullptr) return false;
    if (_front->next == nullptr) {
        OldNum = _front->val;
        delete _front;
        _front = nullptr;
        return true;
    };
    OldNum = ptr->next->val;
    while (ptr->next->next != nullptr) ptr = ptr->next;
    delete ptr->next;
    ptr->next = nullptr;
    return true;
}

/* --- harder ones for test 2 and 3 -- */

/**
 * @brief Delete a node at a given position from the list. The
 * node at position pos is deleted and the value of the deleted node is returned in val.
 * The valid range of pos is 0 to count-1. if pos = 0, delete first node, and pos = count-1 delete last node.
 * @param pos: position of the node to be deleted
 * @param val: it is set to the value of the node to be deleted
 * @return true: if the node was deleted successfully
 * @return false: if the node was not deleted successfully because the position was out of range
 */
bool LinkedList::deleteAt(int pos, T &val)
{
    if (pos < 0 || pos > _count) return false;
    if (pos == 0) return deleteFront(val);
    if (pos == _count) return deleteRear(val);
    // TODO: Add code here
    //  check if the pos is valid first, then move the ptr to the rigth positon
    //  consider the special case of deleting the first node and the last node
    //  Do not forget to set value.
}

/**
 * @brief Insert a value at a specified position in the list. The valid pos is in the range of 0 to count.
 * The value will be inserted before the node at the specified position. if pos = 0, the value will be inserted
 * at the front of the list. if pos = count, the value will be inserted at the rear of the list.
 * @param pos: position to insert the value at.
 * @param val: value to insert.
 * @return true: if the value was inserted.
 * @return false: if the value was not inserted because pos is out of the range.
 */
bool LinkedList::insertAt(int pos, T val)
{
    // TODO: Add code here
    //  check if the pos is valid first, then move the ptr to the rigth positon
    //  consider the special case of inserting the first node and the last node
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other)
{
    // Start with an empty list
    _front = nullptr;
    _rear = nullptr;
    _count = 0;
    // TODO: Add code here. Interate through the other list and add a new node to this list
    // for each node in the other list. The new node should have the same value as the other node.
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other)
{
    if (this != &other)
    { // check if the same object
      // Delete all nodes in this list
      // TODO: Add code here
      // Interate through the other list and add a new node to this list
      // Be sure to set the front and rear pointers to the correct values
      // Be sure to set the count to the correct value
      // TODO: Add code here
    }
    return *this;
}
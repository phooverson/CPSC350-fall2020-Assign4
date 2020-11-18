#include <iostream>
#include "ListNodeT.h"

using namespace std;

template <class myType>
class DoublyLinkedListT{
//single linked list
  private:
    ListNodeT<myType> *front;
    ListNodeT<myType> *back;
    int size;
  public:
    DoublyLinkedListT() {
      front = NULL;
      back = NULL;
      size = 0;
    }

    ~DoublyLinkedListT() {
      // Do this yourself.
      delete front;
      delete back;
    }

    void insertFront(myType d) {
      ListNodeT<myType> *node = new ListNodeT<myType>(d);
      if(size==0){ //Indicates an empty list.
        back = node;
      }
      else {
        front->prev = node;
        node->next = front;
      }
      front = node;
      ++size;
    }

    void insertBack(myType d) {
      ListNodeT<myType> *node = new ListNodeT<myType>(d);
      if(front == NULL) {
        front = back;
      }
      else {
        back->next = node;
        node->next = back;
      }
      back = node;
      ++size;
    }

    void printList() {
      ListNodeT<myType> *curr = front;

      while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
      }
      cout << endl;
    }

    int find(myType value) {
      int pos = -1;
      ListNodeT<myType> *curr = front;
      while (curr != NULL) {
        //iterate until we reach the end and hopefully we find what we are looking for.
        ++pos;
        if (curr->data == value) {
          break;
        }
        curr = curr->next;
      }
        if(curr == NULL) {
          pos = -1;
        }
      return pos;
    }

    myType deletePos(int pos) {
      int p = 0;
      ListNodeT<myType> *curr = front;
      ListNodeT<myType> *prev = front;

      //iterate to the correcet position
      while (p != pos) {
        prev = curr;
        curr = curr->next;
        p++;
      }
      //We found the position and our pointers are in their respective positions.
      prev->next = curr->next;
      curr->next = NULL;

      myType temp = curr->data;
      size--;
      delete curr;
      return temp;
    }

    int removeFront() {
      int temp = front->data;
      ListNodeT<myType> *tempFront = front;
      front = front->next;
      tempFront->next = NULL;
      --size;
      delete tempFront;
      return temp;
    }

    int getSize(){
      return size;
    }

    myType atPos(int pos){
      int p = 0;
      ListNodeT<myType> *curr = front;
      ListNodeT<myType> *prev = front;

      //iterate to the correcet position
      while (p != pos) {
        curr = curr->next;
        p++;
      }

      return curr->data;
    }
};

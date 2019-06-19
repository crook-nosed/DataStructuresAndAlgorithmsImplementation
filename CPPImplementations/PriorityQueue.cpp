// implementation of priority queue data structure using Heap stored in an array as a complete binary tree.
#include <iostream>
#include <cmath>
using namespace std;
class PriorityQueue{
private:
  int maxSize;//max size allowed in the array storing Heap
  int size; // no. of elements in the heap at a given time.
  int *Heap;//array which will store the heap contents.
  int parent(int i); //returns parent of given index i
  int leftChild(int i); //returns left child of given index i
  int rightChild(int i); // returns right child of given index i
  void shiftDown(int i); //performs shift down on index i
  void shiftUp(int i); //performs shift up on index i
  void swap(int* a, int* b); //swapping of any two elements.

public:
  PriorityQueue();
  PriorityQueue(int maxSize);
  ~PriorityQueue();
  void insert(int i);
  int extractMax();
  void remove(int i); //removes the value at index i and returns it
  int getMax();
  void changePriority(int i, int p);
};

PriorityQueue::PriorityQueue():size(0),maxSize(1000)
{
  Heap = new[maxSize];
}

PriorityQueue::PriorityQueue(int ms)
{
  size = 0;
  maxSize = ms;
  Heap = new[maxSize];
}

int PriorityQueue::parent(int i)
{
  return floor((i-1)/2);
}

int PriorityQueue::leftChild(int i)
{
  return 2*i+1;
}

int PriorityQueue::rightChild(int i)
{
  return 2*i+2;
}

void PriorityQueue::shiftUp(int i)
{
  while(i>0 && Heap[parent(i)]<Heap[i])
  {
    swap(&Heap[parent(i)],&Heap[i]);
    i = parent(i);
  }
}

void PriorityQueue::shiftDown(int i)
{
  int maxIndex = i;
  int l = leftChild(i);
  if(l<=size && Heap[l]>Heap[maxIndex])
  {
    maxIndex = l;
  }
  int r = rightChild(i);
  if(r<=size && Heap[r]>Heap[maxIndex])
  {
    maxIndex = r;
  }
  if(i != maxIndex)
  {
    swap(&Heap[maxIndex],&Heap[i]);
    shiftDown(maxIndex);
  }
}

void PriorityQueue::swap(int* a,int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;

}
void PriorityQueue::insert(int val)
{
  if(size == maxSize)
  {
    cout<< "ERROR\n";
    return;
  }
  Heap[size] = val;
  shiftUp(size);
  size++;
}

int PriorityQueue::extractMax()
{
  int res = Heap[0];
  Heap[0] = Heap[size];
  size--;
  shiftDown(0);
  return res;
}

int PriorityQueue::getMax()
{
  return Heap[0];
}

void PriorityQueue::remove(int i)
{
  int maxValue = getMax() + 1000;
  Heap[i] = maxValue;
  shiftUp(i);
  extractMax();
}

// changes the priority at index i to p and adjusts heap afterwards.
void PriorityQueue::changePriority(int i, int p)
{
  int oldP = Heap[i];
  Heap[i] = p;
  if(p > oldP)
  {
    shiftUp(i);
  }
  else
  {
    shiftDown(i);
  }
}

PriorityQueue::~PriorityQueue()
{
  free(Heap);
}


// driver function main

int main(int argc, char const *argv[]) {
  
  return 0;
}

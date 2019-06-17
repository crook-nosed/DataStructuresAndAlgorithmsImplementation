// #include <iostream>
// using namespace std;
//
// class DynamicArray
// {
// private:
//   int capacity;//capacity that the dynamic array can hold at a given time
//   int size;//current no. of elements in dynamic array
//   int* arr;
//   int* tempArr;
// public:
//   DynamicArray();
//   DynamicArray(int i);
//   int Get(int i);
//   void Set(int i,int value);
//   void Remove(int i);
//   void PushBack(int i);
//   int currentSize();
//   int currentCapacity();
//   bool isEmpty();
//   void capacityDoubler();
//   void capacityDivider();
// };
// bool DynamicArray::isEmpty()
// {
//   return size==0;
// }
// DynamicArray::DynamicArray()
// {
//  capacity = 1;
//  size = 0;
//  arr = new int[capacity];
// }
// DynamicArray::DynamicArray(int cap)
// {
//   if(cap%2==0)
//       capacity = cap;
//   else{
//       cout<<"Warning: capacity cannot be odd making it: "<<cap+1<<endl;
//       capacity = cap+1;
//     }
//
//  size = 0;
//  arr = new int[capacity];
// }
//
// int DynamicArray::Get(int i)
// {
//   if(i<0||i>=size){
//      cout<<"ERROR:index out of range\n";
//      return 0;
//    }
//   return arr[i];
//
// }
//
// void DynamicArray::Set(int i,int value)
// {
//   if(size==capacity)
//   {
//     capacityDoubler();
//   }
//   if(isEmpty()||i==value)
//   {
//     arr[i]=value;
//     size++;
//     return;
//   }
//   if(i<0||i>=size){
//      cout<<"ERROR:index out of range\n";
//      return;
//    }
//   arr[i]=value;
//   size++;
//
// }
//
// void DynamicArray::Remove(int i)
// {
//   if(i<0||i>=size)
//      cout<<"ERROR:index out of range\n";
//   for(int j=i;j<=size;j++)
//       arr[j]=arr[j+1];
//   size--;
//   // to dos:
//   // 1. size%2==0 condition should be removed rather size==capacity/2 condition should be added.
//   // 2. here when we use parameterized constructor above we may provide numbers like 6 so if we half that number through the below code
//   //    then we should be careful that the capacity of array should never be even so we should make the capacity +1 as in the parameterized constructor
//   if(size%2==0)
//   {
//     tempArr = new int[(capacity/2)];
//     for(int i=0;i<size-1;i++)
//     {
//       tempArr[i]=arr[i];
//     }
//     free(arr);
//     capacity/=2;
//     arr= new int[capacity];
//     for(int i=0;i<capacity;i++)
//     {
//       arr[i]=tempArr[i];
//     }
//     free(tempArr);
//   }
//
// }
// // pushes the value i into the end of dynamic array
// void DynamicArray::PushBack(int i)
// {
//   if(size==capacity)
//   {
//     capacityDoubler();
//   }
//   arr[size]=i;
//   size++;
// }
//
// void DynamicArray::capacityDoubler()
// {
//   tempArr = new int[2*capacity];
//   for(int i=0;i<size;i++)
//   {
//     tempArr[i]=arr[i];
//   }
//   free(arr);
//   capacity*=2;
//   arr = new int[capacity];
//   // the following for loop represents deep copy of temporary array. previously i was doing shallow copy which was causing logical errors.shallow copy cn be done easily by assignment operator as shown below:
//   // arr=tempArr;-->don't do this
//   for(int i=0;i<capacity;i++)
//   {
//     arr[i]=tempArr[i];
//   }
//
//   free(tempArr);
// }
//
// int DynamicArray::currentSize()
// {
//   return size;
// }
//
// int DynamicArray::currentCapacity()
// {
//   return capacity;
// }
//
// int main()
// {
//   int num,val;
//   cin>>num;
//   DynamicArray vec(num);
//   // vec.PushBack(1);
//   // vec.PushBack(2);
//   // vec.PushBack(3);
//   // vec.PushBack(4);
//   // vec.PushBack(5);
//   // cout<<vec.currentSize()<<" "<<vec.currentCapacity()<<endl;
//   // for(int i=0;i<5;i++)
//   // {
//   //   cout<<vec.Get(i)<<endl;
//   // }
//
//   cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
//   for(int i=0;i<15;i++)
//   {
//     vec.Set(i,i);
//   }
//   for (size_t i = 0; i < 15; i++) {
//     /* code */
//     cout<<vec.Get(i)<<"\n";
//   }
//     cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
//   // vec.Remove()
//   return 0;
// }
#include <iostream>
using namespace std;

class DynamicArray
{
private:
  int capacity;//capacity that the dynamic array can hold at a given time
  int size;//current no. of elements in dynamic array
  int* arr;
  int* tempArr;
public:
  DynamicArray();
  DynamicArray(int i);
  int Get(int i);
  void Set(int i,int value);
  void Remove(int i);
  void PushBack(int i);
  int currentSize();
  int currentCapacity();
  bool isEmpty();
  void capacityDoubler();
  void capacityDivider();
};
bool DynamicArray::isEmpty()
{
  return size==0;
}
DynamicArray::DynamicArray()
{
 capacity = 1;
 size = 0;
 arr = new int[capacity];
}
DynamicArray::DynamicArray(int cap)
{
  if(cap%2==0)
      capacity = cap;
  else{
      cout<<"Warning: capacity cannot be odd making it: "<<cap+1<<endl;
      capacity = cap+1;
    }

 size = 0;
 arr = new int[capacity];
}

int DynamicArray::Get(int i)
{
  if(i<0||i>=size){
     cout<<"ERROR:index out of range\n";
     return 0;
   }
  return arr[i];

}

void DynamicArray::Set(int i,int value)
{
  if(size==capacity)
  {
    capacityDoubler();
  }
  if(isEmpty()||i==value)
  {
    arr[i]=value;
    size++;
    return;
  }
  if(i<0||i>size){
     cout<<"ERROR:index out of range\n";
     return;
   }
  arr[i]=value;
  size++;

}

void DynamicArray::Remove(int i)
{
  if(i<0||i>=size)
     cout<<"ERROR:index out of range\n";
  for(int j=i;j<size;j++)
      arr[j]=arr[j+1];
  size--;
  // to dos:
  // 1. size%2==0 condition should be removed rather size==capacity/2 condition should be added.
  // 2. here when we use parameterized constructor above we may provide numbers like 6 so if we half that number through the below code
  //    then we should be careful that the capacity of array should never be even so we should make the capacity +1 as in the parameterized constructor
  if(size==capacity/2)
  {
    capacityDivider();
  }

}
// pushes the value i into the end of dynamic array
void DynamicArray::PushBack(int i)
{
  if(size==capacity)
  {
    capacityDoubler();
  }
  arr[size]=i;
  size++;
}

void DynamicArray::capacityDoubler()
{
  tempArr = new int[2*capacity];
  for(int i=0;i<size;i++)
  {
    tempArr[i]=arr[i];
  }
  free(arr);
  capacity*=2;
  arr = new int[capacity];
  // the following for loop represents deep copy of temporary array. previously i was doing shallow copy which was causing logical errors.shallow copy cn be done easily by assignment operator as shown below:
  // arr=tempArr;-->don't do this
  for(int i=0;i<capacity;i++)
  {
    arr[i]=tempArr[i];
  }

  free(tempArr);
}
void DynamicArray::capacityDivider()
{
    tempArr = new int[(capacity/2)];
    for(int i=0;i<size;i++)
    {
      tempArr[i]=arr[i];
    }
    free(arr);
    capacity/=2;
    if(capacity%2!=0 && capacity!=1)
    {
      cout<<"Warning: capacity cannot be odd making it: "<<capacity+1<<endl;
      capacity++;
    }
    arr= new int[capacity];
    for(int i=0;i<capacity;i++)
    {
      arr[i]=tempArr[i];
    }
    free(tempArr);
}

int DynamicArray::currentSize()
{
  return size;
}

int DynamicArray::currentCapacity()
{
  return capacity;
}

int main()
{
  int num,val;
  cin>>num;
  DynamicArray vec(num);
  // vec.PushBack(1);
  // vec.PushBack(2);
  // vec.PushBack(3);
  // vec.PushBack(4);
  // vec.PushBack(5);
  // cout<<vec.currentSize()<<" "<<vec.currentCapacity()<<endl;
  // for(int i=0;i<5;i++)
  // {
  //   cout<<vec.Get(i)<<endl;
  // }

  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
  for(int i=0;i<6;i++)
  {
    vec.Set(i,i);
  }
  for (size_t i = 0; i <6; i++) {
    /* code */
    cout<<vec.Get(i)<<"\n";
  }

    cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
  // vec.Remove()
  vec.Remove(0);
  cout<<vec.Get(0)<<"\n";
  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
    vec.Remove(0);
  cout<<vec.Get(0)<<"\n";
  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
    vec.Remove(0);
  cout<<vec.Get(0)<<"\n";
  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
  vec.Remove(0);
  cout<<vec.Get(0)<<"\n";
  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
  vec.Remove(0);
  cout<<vec.Get(0)<<"\n";
  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
  vec.Remove(0);
  cout<<vec.Get(0)<<"\n";
  cout<<"Current Size is: "<<vec.currentSize()<<" "<<"And current capacity is: "<<vec.currentCapacity()<<"\n";
  return 0;
}

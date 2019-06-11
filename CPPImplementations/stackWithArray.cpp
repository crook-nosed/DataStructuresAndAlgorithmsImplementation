#define MAX_SIZE 1000
#include <iostream>
class StackA
{
private:
  int arr[MAX_SIZE];
  int numOfElements;
  int top;
public:
StackA();
void Push(int i);
int Top();
int Pop();
bool isEmpty();
void traverse();

};
StackA::StackA():numOfElements{0},top{0}
{}
void StackA::Push(int i)
{
  if(numOfElements>MAX_SIZE)
  {
    std::cout<<"Max size for stack reached!!\n";
    return;
  }
  numOfElements++;
  top=numOfElements-1;
  arr[top]=i;
}
int StackA::Top()
{
  if(isEmpty())
  {
    std::cout<<"Empty Stack\n";
    return 0;
  }
  return arr[top];
}
int StackA::Pop()
{
  if(isEmpty())
  {
    std::cout<<"No elements to pop\n";
    return -1;
  }
  int t = Top();
  numOfElements--;
  top--;
  return t;
}
bool StackA::isEmpty()
{
  return numOfElements==0;
}
void StackA::traverse()
{
  for(int i=numOfElements-1;i>=0;i--)
  std::cout<<arr[i]<<" ";
  std::cout<<"\n";
}
int main()
{
	StackA s;
	for (int i=0;i<5;i++)
  {
    std::cin>>i;
    s.Push(i);

  }

	std::cout<<s.Top()<<std::endl;
	s.traverse();
  for(int i=0;i<5;i++){
  std::cout<<s.Pop()<<" ";
  std::cout<<"\n";
}
s.Pop();
	 return 0;
}

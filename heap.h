#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

private:
  /// Add whatever helper functions and data members you need below
int base_m;
PComparator comparator;
std::vector<T> data;
void trickleUp(int loc);
void trickleDown(int loc);


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator> :: Heap(int m, PComparator c): base_m(m), comparator(c)
{

}
template <typename T, typename PComparator>
Heap<T,PComparator> :: ~Heap()
{

}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return ( data[0]);

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Heap is empty");
  }
  data[0]=data.back();
  data.pop_back();
  if(data.empty()){
        return;
    }
  trickleDown(0);
  
/*Uncomment to check contents after each pop() call */

  //  for(long unsigned int i=0;i<data.size();i++)
  // {
  //   cout<<data[i]<<" ";
  // }cout<<endl;

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
  trickleUp(data.size()-1);
}
template<typename T, typename PComparator>
void Heap<T,PComparator>:: trickleDown(int loc)
{
    if((unsigned long int)base_m*loc+1 > data.size()-1 )
    {
      return;
    }
    else
    {
       size_t betterChild;
        for(int i=1; i<base_m;i++)
        {
        betterChild= (base_m*loc)+i ;
        if(betterChild > data.size()-1)
        {
          break;
        }
        if( (betterChild+1) <= data.size()-1) //if right child exists
        {
          size_t rightChild= betterChild+ 1;
          if(comparator(data[rightChild], data[betterChild]))
          {
            betterChild=rightChild;
          }
        }
        if(comparator (data[betterChild],data[loc]))
        {
          std::swap( data[loc], data[betterChild]);
          trickleDown(betterChild);
        }
       }
    }
}


template<typename T, typename PComparator>
void Heap<T,PComparator>:: trickleUp(int loc)
{
    int parent=(loc-1)/base_m;
    while(parent>=0 && (comparator(data[loc], data[parent])))
    {
      std::swap(data[parent], data[loc]);
      loc=parent;
      parent=(loc-1)/base_m;
    }
}
template<typename T, typename PComparator>
bool Heap<T,PComparator>:: empty()const
{
  return(data.empty()); 
}

#endif


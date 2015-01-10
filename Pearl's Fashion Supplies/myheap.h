/* 
 * File:   myheap.h
 * Author: Yi Jin
 * ID: 4370673
 * Created on October 22, 2014, 10:54 PM
 */

#ifndef MYHEAP_H
#define	MYHEAP_H
#include<iostream>  
using namespace std;

template<class T>   
class MiniHeap   
{    
    public:   
        MiniHeap(int maxheapsize=10);   
        ~MiniHeap(){delete []heap;}   
  
        int Size() const{return currentsize;}   
        T Max(){if(currentsize) return heap[1];}   
  
        MiniHeap<T>& Insert(const T& x);   
        MiniHeap<T>& DeleteMin(T &x);   
  
        void Initialize(T x[], int size, int ArraySize);   
        void Deactivate();     
    private:   
        int currentsize, maxsize;   
        T *heap;   
};   
  
template <class T>   
MiniHeap<T>::MiniHeap(int maxheapsize)   
{   
    maxsize=maxheapsize;   
    heap=new T[maxsize+1];   
    currentsize=0;   
}   
  
template<class T>   
MiniHeap<T>& MiniHeap<T>::Insert(const T& x)   
{   
    if(currentsize==maxsize)     
        return *this;   
      
    int i=++currentsize;   
    while(i !=1&&x<heap[i/2])   
    {   
        heap[i]=heap[i/2];   
        i/=2;   
    }   
  
    heap[i]=x;   
    return *this;   
}   
  
template<class T>   
MiniHeap<T>& MiniHeap<T>::DeleteMin(T& x)   
{   
    if(currentsize==0)   
    {   
        cout<<"Empty heap!!!"<<endl;   
        return *this;   
    }   
  
    x=heap[1];   
  
    T y=heap[currentsize--];   
    int i=1,ci=2;   
    while(ci<=currentsize)   
    {   
        if(ci<currentsize&&heap[ci]>heap[ci+1])     
            ci++;      
  
        if(y<=heap[ci])      
            break;   
          
        heap[i]=heap[ci];   
        i=ci;   
        ci*=2;   
    }   
  
    heap[i]=y;   
    return *this;   
}   
  
template<class T>   
void MiniHeap<T>::Initialize(T x[],int size,int ArraySize)   
{   
    delete []heap;   
    heap=x;   
    currentsize=size;   
    maxsize=ArraySize;   
  
    for(int i=currentsize/2;i>=1;i--)   
    {   
        T y=heap[i];   
        int c=2*i;   
        while(c<=currentsize)   
        {   
            if(c<currentsize&&heap[c]>heap[c+1])   
                c++;   
            if(y<=heap[c])   
                break;   
            heap[c/2]=heap[c];   
            c*=2;   
        }   
        heap[c/2]=y;   
    }   
}   
  
template<class T>   
void MiniHeap<T>::Deactivate()   
{   
    heap=0;   
}   

#endif	/* MYHEAP_H */

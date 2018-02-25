//
//  SharedPtr.hpp
//  SharedPtr
//
//  Created by 顾浩 on 24/2/18.
//  Copyright © 2018 顾浩. All rights reserved.
//

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

using namespace std;

template<typename T>
class SharedPtr {
public:
    SharedPtr() : _ptr((T *)0), _refCount(0)
    {
    }
    
    SharedPtr(T *obj) : _ptr(obj), _refCount(new int(1))
    {
        cout<<"create object : "<<*_ptr<<"\trefCount = 1"<<endl;
    }
    
    SharedPtr(SharedPtr &other) : _ptr(other._ptr), _refCount(&(++*other._refCount))
    {
		cout<<"copy constructor : "<<*_ptr<<"\trefCount = "<<*_refCount<<endl;
    }
    
    ~SharedPtr()
    {
        if(_ptr && --*_refCount == 0) {
            cout<<*_ptr<<"\trefCount = 0. delete the _ptr:"<<*_ptr<<endl;
            delete _ptr;
            delete _refCount;
        }
    }
    
    SharedPtr &operator=(SharedPtr &other)
    {
        if(this==&other)
            return *this;
        
        ++*other._refCount;
        if(--*_refCount == 0) {
            cout<<"in function operator = . delete "<<*_ptr<<endl;
            delete _ptr;
            delete _refCount;
        }
        
        _ptr = other._ptr;
        _refCount = other._refCount;
        cout<<"in function operator = . "<<*_ptr<<"\t_refCount = "<<*_refCount<<endl;
        return *this;
    }
    
    T *operator->()
    {
        if(_refCount == 0)
            return 0;
        
        return _ptr;
    }
    
    T &operator*()
    {
        if (_refCount == 0)
            return (T*)0;
        
        return *_ptr;
    }
    
private:
    T *_ptr;
    int *_refCount;     //should be int*, rather than int
};

#endif /* SharedPtr_h */

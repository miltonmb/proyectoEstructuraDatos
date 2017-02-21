#pragma once
#include "object.h"

class ADTList:public Object{
 private:
     ADTList(const ADTList&);
 protected:
    int sizeVar;
 public:
    ADTList();
    virtual ~ADTList();
    virtual bool insert(Object*, int) = 0;
    virtual Object* first()const = 0;
    virtual Object* last()const = 0;
    int size()const;
    virtual int capacity()const = 0;
    virtual Object* remove(int) = 0;
    bool isEmpty() const;
    virtual bool isFull() const = 0;
    virtual int indexOf(Object*) = 0;
    virtual Object* get(int) = 0;
    virtual void clear() = 0;
};

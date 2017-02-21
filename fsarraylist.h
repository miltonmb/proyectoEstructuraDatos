#pragma once
#include "adtlist.h"
#include "object.h"
class FSArrayList : public ADTList{
 protected:
    int capacityVar;
    Object** data;

 public:
    FSArrayList(int);
    virtual ~FSArrayList();
    virtual bool insert(Object*, int);
    virtual Object* first()const;
    virtual Object* last()const;
    virtual int capacity()const;
    virtual Object* remove(int);
    virtual bool isFull() const;
    virtual int indexOf(Object*);
    virtual Object* get(int);
    virtual void clear();
};



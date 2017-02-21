#include "varraylist.h"

VArrayList::VArrayList(double delta):FSArrayList(5){
    if (delta <= 0)
        this->delta = 6;
    else 
        this->delta = delta;
}

VArrayList::~VArrayList(){
    for (int i=0; i<sizeVar; i++)
        delete data[i];
    delete[] data;
}
bool VArrayList::insert(Object* element, int pos){
    if (isFull()) {
        resize();
    }
    FSArrayList::insert(element, pos);
}

void VArrayList::resize(){
    int newSize = sizeVar + sizeVar * delta;
    Object** temp = new Object*[newSize];

    for (int i = 0; i < sizeVar; i++) {
        temp[i] = data[i];
    }
    for (int i = sizeVar; i < newSize; i++) {
        temp[i] = NULL;
    }
    data = temp;
    sizeVar = newSize;
}
#include "fsarraylist.h"

FSArrayList::FSArrayList(int capacityVar): capacityVar(capacityVar){
    data = new Object*[capacityVar];
    for (int i=0; i<capacityVar; i++)
        data[i] = NULL;
}

FSArrayList::~FSArrayList(){
    for (int i=0; i<sizeVar; i++)
        delete data[i];
    delete[] data;
}
bool FSArrayList::insert(Object* element, int pos){
    if (pos < 0 || pos > sizeVar)
        return false;
    if (sizeVar == capacityVar)
        return false;
    if (pos == sizeVar)
        data[pos] = element;
    else{
        for (int i=sizeVar; i>pos; i--)
            data[i] = data[i-1];
        data[pos] = element;
    }
    sizeVar++;
    return true;
}
Object* FSArrayList::first()const{
    if (sizeVar == 0) {
        return NULL;
    }
    return this->data[0];
}
Object* FSArrayList::last()const{
    if (sizeVar > 0) {
        return NULL;
    }
    return this->data[sizeVar - 1];
}
int FSArrayList::capacity()const{
    return this->capacityVar;
}
Object* FSArrayList::remove(int pos){
    if (pos >= capacityVar || pos >= sizeVar) {
        return NULL;
    }

    if (pos < sizeVar - 1) {
        for (int i = pos; i < sizeVar; i++) {
            data[i] = data[i + 1];
        }        
    }

    data[pos] = NULL;
    delete data[pos];
    sizeVar--;

}
bool FSArrayList::isFull() const{
    return sizeVar == capacityVar;
}
int FSArrayList::indexOf(Object* element){
    for (int i = 0; i < sizeVar; i++) {
        if (data[i]->equals(element)) {
            return i;
        }
    }
    return -1;
}
Object* FSArrayList::get(int pos){
    if (pos >= capacityVar || pos >= sizeVar) {
        return NULL;
    }
    return data[pos];
}
void FSArrayList::clear(){
    for (int i = 0; i < sizeVar; i++) {
        data[i] = NULL;
        delete data[i];
    }
    sizeVar = 0;
}

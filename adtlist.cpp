#include "adtlist.h"
ADTList::ADTList(const ADTList& other){}
ADTList::ADTList():sizeVar(0){
}
ADTList::~ADTList(){
}
int ADTList::size()const{
    return sizeVar;
}
bool ADTList::isEmpty() const{
    return sizeVar == 0;
}

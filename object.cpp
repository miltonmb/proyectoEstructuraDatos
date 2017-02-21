#include "object.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
Object::Object(){
}

Object::~Object(){
}

string Object::toString()const{
    stringstream ss;
    ss << "Object@" << this;
    return ss.str();
}
bool Object::equals(Object* other)const{
    return this == other;
}

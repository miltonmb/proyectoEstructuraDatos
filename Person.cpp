#include "object.h"
#include "Person.h"
#include <sstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define CLEAR "\033[2J"  // clear screen escape code 
using namespace std;
Person::Person(){

}

Person::Person(string name){
	this->name = name;
}

string Person::toString()const{
	stringstream ss;
	ss <<BLUE<< " Nombre: "<<RESET<<GREEN<< name<<RESET;
	ss << ",";
	return ss.str();
}

bool Person::equals(Object* other)const{
	if(!dynamic_cast<Person*>(other)){
		return false;
	}
	Person* p = dynamic_cast<Person*>(other);
	return p-> name == name;
}
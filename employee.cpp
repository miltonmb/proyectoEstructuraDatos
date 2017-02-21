#include "object.h"
#include "employee.h"
#include "Person.h"
#include <sstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define CLEAR "\033[2J"  // clear screen escape code 
using namespace std;
employee::employee(){

}
/*el constructor sobrecargado de employee recibe los elementos del padre,
en este caso Person, y los pertenecientes a employee que solo seria Salary */
employee::employee(string name, string puesto, double salary):Person(name),puesto(puesto),salary(salary){
}

/*El toString se llama al toString del padre
para asi poder imprimir todos sus datos*/
string employee::toString()const{
	stringstream ss;
	ss <<BLUE<<"Puesto: "<<RESET<<GREEN<<puesto<<RESET;
	ss <<",";
	ss << Person::toString();
	ss <<BLUE<< " Salario: "<<RESET<<GREEN<<salary<<RESET;
	return ss.str();
}
/*Devuelve el Salario del empleado*/
double employee::getSalary()const{
	return this->salary;
}
/*Setea un nuevo salario al empleado*/
void employee::setSalary(double salary){
	this->salary = salary;
}
#pragma once
#include "object.h"
#include "Person.h"
#include <string>
using namespace std;
class employee: public Person{
	double salary;
	string puesto;
	public:
		employee();
		employee(string,string,double);
		virtual string toString()const;
		double getSalary()const;
		void setSalary(double);
};




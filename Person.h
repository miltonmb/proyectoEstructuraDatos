#pragma once
#include "object.h"
class Person: public Object{
	private:
		string name;

	public:
		Person();
		Person(string);
		virtual string toString()const;
		virtual bool equals(Object*)const;
};




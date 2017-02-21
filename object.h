#pragma once
#include <string>
using std::string;

class Object
{
    public:
        Object();
        virtual string toString()const;
        virtual bool equals(Object*)const;
        virtual ~Object();

    protected:

    private:
};


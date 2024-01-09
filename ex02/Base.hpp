#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

#include <stdlib.h>		/* srand, rand */
#include <time.h>		/* time */


class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:03:08 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/27 08:02:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main(void)
{
	int		i = 0;
	Base	*b;

	std::srand(std::time(nullptr));
	while (i < 20)
	{
		b = generate();
		identify(b);
		identify(*b);
		delete b;
		i++;
	}
}

Base	*generate(void)
{
	Base	*b;

	switch (rand() % 3) {
		case 0:
			b = new A();
			std::cout << "A generated" << std::endl;
			break ;
		case 1:
			b = new B();
			std::cout << "B generated" << std::endl;
			break ;
		case 2:
			b = new C();
			std::cout << "C generated" << std::endl;
			break ;
	}
	return (b);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A found by ptr" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B found by ptr" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C found by ptr" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A found by ref" << std::endl;
	}
	catch (std::bad_cast e) {}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B found by ref" << std::endl;
	}
	catch (std::bad_cast e) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C found by ref" << std::endl;
	}
	catch (std::bad_cast e) {}
}

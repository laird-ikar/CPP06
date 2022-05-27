/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:03:34 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/27 07:45:35 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

void to_char(double d);
void to_int(double d);
void to_float(double d, int prec);

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage : ./ex00 [thing to convert]" << std::endl;
		return (1);
	}
	double res;
	if (std::strlen(argv[1]) == 1 && !std::isdigit(argv[1][0]))
		res = double (argv[1][0]);
	else
		res = std::strtod(argv[1], nullptr);
	to_char(res);
	to_int(res);
	int prec = std::strlen(std::strchr(argv[1], '.')?std::strchr(argv[1], '.'):"") - 1;
	to_float(res, prec);
	std::cout << "double : " << std::setprecision(std::min(std::max(prec, 1), 52)) << std::showpoint << std::fixed << res << std::endl;

	return 0;
}

void to_char(double d)
{
	if (d < -128 || d > 127 || isnan(d))
	{
		std::cout <<  "char : impossible" << std::endl;
		return ;
	}
	char	c = char(d);

	if (std::isprint(c))
		std::cout << "char : " << c << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

}

void to_int(double d)
{
	if (d > 2147483647 || d < -2147483648 || isnan(d))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << int(d) << std::endl;
}

void to_float(double d, int prec)
{
	if ((d < -3.40282e+038 || d > 3.40282e+038) && (!isinf(d)))
	{
		std::cout << "float : impossible" << std::endl;
		return;
	}
	std::cout << "float : "  << std::setprecision(std::min(std::max(prec, 1), 23)) << std::showpoint << std::fixed << float(d) << "f" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:38:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/26 16:55:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

typedef struct s_Data {
	int		i;
	char	c;
}	Data;

uintptr_t	serialize(Data* ptr);
Data		*deserialize(uintptr_t raw);

int	main(void)
{
	Data		*ptr = new Data;
	Data		*ptr2 = new Data;
	uintptr_t	raw;

	ptr->i = 42;
	ptr->c = '*';
	std::cout << ptr << ":" << ptr->i << ptr->c << std::endl;
	raw = serialize(ptr);
	ptr2 = deserialize(raw);
	std::cout << ptr2 << ":" << ptr2->i << ptr2->c << std::endl;
	return 0;
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

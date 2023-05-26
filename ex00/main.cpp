/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:28:51 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/26 07:08:48 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Brian("Brian");
	ClapTrap	Steven("Steven");
	ClapTrap	TheWok("Dwayne");

	std::cout << "Brian attacks Steven and his imaginary friend Gandalf because they couldn't recite the Bing Chilling verse" << std::endl;
	Brian.attack("Steven");
	Brian.attack("Gandalf");
	std::cout << "That was mean! Now Steven needs to repair himself" << std::endl;
	for (int i = 0; i < 12; i++)
		Steven.beRepaired(1);
	std::cout << "Unfortunately, Steven is very clumsy and bangs his head against the doorframe...several times :/" << std::endl;
	for (int i = 0; i < 3; i++)
		Steven.takeDamage(2);
	std::cout << "(Un)Luckily, Brian is just as clumsy, if not more!" << std::endl;
	Brian.takeDamage(42);
	std::cout << "Brian tries attacking again" << std::endl;
	Brian.attack("Steven");
	std::cout << "Brian tries repairing himself" << std::endl;
	Brian.beRepaired(10);
	std::cout << "Steven's revenge!" << std::endl;
	Steven.attack("Brian");
	std::cout << "DWAAAYNNNEEE JOHNSOOOON" << std::endl;
	for (int i = 0; i < 11; i++)
		TheWok.attack("Steven");
	TheWok.beRepaired(50);
	TheWok.takeDamage(2);
	std::cout << "Alright, enough with the abuse" << std::endl;
	return (0);
}

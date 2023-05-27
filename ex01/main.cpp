/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:28:51 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/26 08:53:09 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Brian("Brian");
	ScavTrap	John("Cena");
	ScavTrap	TheWok("Johnson");

	std::cout << "TheWok Johnson is attacking Brian!" << std::endl;
	TheWok.attack("Brian");
	std::cout << "Ouch, Brian must repair and counter" << std::endl;
	Brian.beRepaired(42);
	Brian.attack("Johnson");
	std::cout << "Dwayne The Wok Johnson now has to defend the gate" << std::endl;
	TheWok.guardGate();
	TheWok.beRepaired(1000);
	std::cout << "John Cena wants to attack the gate!" << std::endl;
	John.attack("Johnson");
	for (int i = 0; i < 50; i++)
		John.attack("Johnson");
	std::cout << "John Cena wasn't able to defeat the Wok, and damages himself by facepalming" << std::endl;
	John.takeDamage(1);
	return (0);
}

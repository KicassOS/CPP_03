/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:28:51 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/27 06:13:10 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	Hans("Niemann");
	ScavTrap	John("Cena");
	ScavTrap	TheWok("Johnson");
	FragTrap	Magnoos("Carlsen");

	std::cout << "Carlsen is attacking Hans Niemann!" << std::endl;
	Magnoos.attack("Niemann");

	std::cout << "Ouch, Niemann must repair and counter" << std::endl;
	Hans.beRepaired(42);
	Hans.attack("Carlsen");
	std::cout << "Chess.com diff right there" << std::endl;

	std::cout << "Cena and the Wok slap Niemann as well" << std::endl;
	John.attack("Niemann");
	TheWok.attack("Niemann");

	Magnoos.highFivesGuys();

	std::cout << "The three survivors attack eachother once" << std::endl;
	TheWok.attack("Carlsen");
	TheWok.attack("Cena");
	John.attack("Carlsen");
	John.attack("Johnson");
	Magnoos.attack("Cena");
	Magnoos.attack("Johnson");
	std::cout << "Carlsen takes damage because his ego was destroyed by the loss" << std::endl;
	Magnoos.takeDamage(54);
	std::cout << "Chess.com wipes his tears and so Carlsen repairs himself" << std::endl;
	Magnoos.beRepaired(22);
	TheWok.guardGate();
	John.guardGate();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 05:48:46 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/27 06:16:45 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "Default name";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	this->addSelfToTargets();
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap " << name << " name parameter constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	this->addSelfToTargets();
}

FragTrap::FragTrap(const FragTrap& ScavTrapRef): ClapTrap(ScavTrapRef._name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->_name = ScavTrapRef._name;
	this->_hit_points = ScavTrapRef._hit_points;
	this->_energy_points = ScavTrapRef._energy_points;
	this->_attack_damage = ScavTrapRef._attack_damage;

	this->addSelfToTargets();
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap assignement copy constructor called" << std::endl;
	if (this == &rhs)
		return (*this);
	
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;

	this->addSelfToTargets();
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
	this->removeSelfFromTargets();
	return;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << ": Yo guys give me five!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:20:53 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/26 08:51:59 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "Default name";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;

	this->addSelfToTargets();
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap " << name << " name parameter constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;

	this->addSelfToTargets();
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrapRef): ClapTrap(ScavTrapRef._name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_name = ScavTrapRef._name;
	this->_hit_points = ScavTrapRef._hit_points;
	this->_energy_points = ScavTrapRef._energy_points;
	this->_attack_damage = ScavTrapRef._attack_damage;

	this->addSelfToTargets();
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap assignement copy constructor called" << std::endl;
	if (this == &rhs)
		return (*this);
	
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;

	this->addSelfToTargets();
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
	this->removeSelfFromTargets();
	return;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points < 1)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy points to attack" << std::endl;
		return;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no health points and therefore cannot attack" << std::endl;
		return;
	}
	ScavTrap*	target_claptrap = (ScavTrap*) this->getClapTrapByName(target);
	if (target_claptrap == NULL)
	{
		// assume it's a made up/imaginary target
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	target_claptrap->takeDamage(this->_attack_damage);
	this->_energy_points--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " entered gatekeeper mode!" << std::endl;
}

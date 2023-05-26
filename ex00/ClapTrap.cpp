/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:28:49 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/26 07:14:27 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int			ClapTrap::_number_of_targets = 0;
void*		ClapTrap::_target_instances[42] = {0};
std::string	ClapTrap::_target_names[42] = {""};


ClapTrap::ClapTrap(void): _name("Default_name"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;

	this->addSelfToTargets();
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << name << " name parameter constructor called" << std::endl;

	this->addSelfToTargets();
}

ClapTrap::ClapTrap(const ClapTrap& ClapTrapRef)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = ClapTrapRef._name;
	this->_hit_points = ClapTrapRef._hit_points;
	this->_energy_points = ClapTrapRef._energy_points;
	this->_attack_damage = ClapTrapRef._attack_damage;

	this->addSelfToTargets();
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap assignement copy constructor called" << std::endl;
	if (this == &rhs)
		return (*this);
	
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;

	this->addSelfToTargets();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
	this->removeSelfFromTargets();
	return;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points < 1)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points to attack" << std::endl;
		return;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no health points and therefore cannot attack" << std::endl;
		return;
	}
	ClapTrap*	target_claptrap = this->getClapTrapByName(target);
	if (target_claptrap == NULL)
	{
		// assume it's a made up/imaginary target
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	target_claptrap->takeDamage(this->_attack_damage);
	this->_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage!" << std::endl;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hit_points << " hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points < 1)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points to repair itself!" << std::endl;
		return;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more hit points and therefore cannot repair itself!" << std::endl;
		return;
	}
	this->_hit_points += amount;
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " was repaired by " << amount << " hit points!" << std::endl;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hit_points << " hit points" << std::endl;
}

ClapTrap*	ClapTrap::getClapTrapByName(std::string name)
{
	for (int i = 0; i < ClapTrap::_number_of_targets; i++)
	{
		if (ClapTrap::_target_names[i] == name && ClapTrap::_target_instances[i] != this)
			return ((ClapTrap*) ClapTrap::_target_instances[i]);
	}
	return (NULL);
}

void	ClapTrap::addSelfToTargets(void)
{
	if (ClapTrap::_number_of_targets >= 42)
	{
		std::cout << "Cannot add more targets to target list" << std::endl;
		return;
	}
	ClapTrap::_target_names[ClapTrap::_number_of_targets] = this->_name;
	ClapTrap::_target_instances[ClapTrap::_number_of_targets] = this;
	ClapTrap::_number_of_targets++;
}

void	ClapTrap::removeSelfFromTargets(void)
{
	for (int i = 0; i < _number_of_targets; i++)
	{
		if (ClapTrap::_target_names[i] == this->_name)
		{
			ClapTrap::_target_names[i] = "";
			break;
		}
	}

	for (int i = 0; i < ClapTrap::_number_of_targets; i++)
	{
		if (ClapTrap::_target_instances[i] == this)
		{
			ClapTrap::_target_instances[i] = NULL;
			break;
		}
	}
}

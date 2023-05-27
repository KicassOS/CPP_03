/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:28:46 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/26 08:24:35 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap(void);											// canonical
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ClapTrapRef);					// canonical
		ClapTrap&	operator=(const ClapTrap& rhs);				// canonical
		virtual	~ClapTrap(void); //								// canonical

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

		void*	getClapTrapByName(std::string name);
		void		removeSelfFromTargets(void);
		void		addSelfToTargets(void);

		static std::string	_target_names[42];
		static void*		_target_instances[42];
		static int			_number_of_targets;
};

#endif
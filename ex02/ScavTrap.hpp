/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:20:11 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/26 08:51:00 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
		public:
		ScavTrap(void);											// canonical
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ClapTrapRef);					// canonical
		ScavTrap&	operator=(const ScavTrap& rhs);				// canonical
		virtual	~ScavTrap(void); 								// canonical

		void	guardGate(void);
		void	attack(std::string const &target);
};

#endif
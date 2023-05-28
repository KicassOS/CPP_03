/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 05:47:52 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/28 09:58:25 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);											// canonical
		FragTrap(std::string name);
		FragTrap(const FragTrap& ClapTrapRef);					// canonical
		FragTrap&	operator=(const FragTrap& rhs);				// canonical
		virtual	~FragTrap(void); 								// canonical

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 10:48:43 by gabrlee           #+#    #+#              #
#    Updated: 2026/11/10 10:48:44 by gabrlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
	if (unit == "packets"):
		print(f"{seed_type.capitalize()} seeds: {quantity} packets available")
	elif (unit == "grams"):
		print(f"{seed_type.capitalize()} seeds: {quantity} grams total")
	elif (unit == "area"):
		print(f"{seed_type.capitalize()} seeds: covers {quantity} square meters")
	else:
		print("Unknown unit type")	

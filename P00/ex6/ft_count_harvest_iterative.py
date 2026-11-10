# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 10:48:38 by gabrlee           #+#    #+#              #
#    Updated: 2026/11/10 10:48:39 by gabrlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_iterative():
	harvest = int(input("Days until harvest: "))
	for i in range(harvest):
		print(f"Day {i + 1}")
	print("Harvest time!")

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 10:48:40 by gabrlee           #+#    #+#              #
#    Updated: 2026/11/10 10:48:41 by gabrlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_recursive():
	harvest = int(input("Days until harvest: "))
	helper(0, harvest)


def helper(days, harvest):
	if (days == harvest):
		print("Harvest time!")
	else:
		print(f"Day {days + 1}")
		helper(days + 1, harvest)

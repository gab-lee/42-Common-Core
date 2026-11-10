# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 10:48:29 by gabrlee           #+#    #+#              #
#    Updated: 2026/11/10 10:48:30 by gabrlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_harvest_total():
	d1 = int(input("Day 1 harvest: "))
	d2 = int(input("Day 2 harvest: "))
	d3 = int(input("Day 3 harvest: "))
	print(f"Total harvest: {d1 + d2 + d3}")

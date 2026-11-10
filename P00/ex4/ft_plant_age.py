# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 10:48:32 by gabrlee           #+#    #+#              #
#    Updated: 2026/11/10 10:48:33 by gabrlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_plant_age():
	age = int(input("Enter plant age in days: "))
	if (age > 60):
		print("Plant is ready to harvest!")
	else:
		print("Plant needs more time to grow.")

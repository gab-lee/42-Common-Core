# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 10:48:36 by gabrlee           #+#    #+#              #
#    Updated: 2026/11/10 10:48:37 by gabrlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
	water = int(input("Days since last watering: "))
	if (water > 2):
		print("Water the plants!")
	else:
		print("Plants are fine")

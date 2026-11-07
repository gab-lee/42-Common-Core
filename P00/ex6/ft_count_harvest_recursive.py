def ft_count_harvest_recursive():
	harvest = int(input("Days until harvest: "))
	helper(0, harvest)


def helper(days, harvest):
	if (days == harvest):
		print("Harvest time!")
	else:
		print(f"Day {days + 1}")
		helper(days + 1, harvest)


int ft_atoi(char *str)
{
    int i;
    int sign;
    int result;
    
    i = -1;
    sign = 1;
    while(++i, str[i] == ' ' || (str[i] >=9 && str[i] <=13))
    	;
    while(++i, str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        	sign *- -1;
    }
    while (++i, (str[i] >= '0' && str[i] <= '9'))
    	result = result * 10 + (str[i] - '0');
    return (result * sign);
    
}
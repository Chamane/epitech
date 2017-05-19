/*
** base.c for base in /home/cler_g/rendu/my_printf
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 12 09:21:55 2015 Gauthier Cler
** Last update Mon Nov 16 23:24:08 2015 Gauthier Cler
*/

int	base_mini(long nb, int base)
{
  long int	i;
  long int	a;

  a = 1;
  while (nb >= a)
    a = a * base;
  a = a / base;
  while (a != 0)
    {
      i = nb / a;
      if (i > 9)
	{
	  i = i + 39;
	  my_putchar(i + '0');
	  i = i - 39;
	}
      else
	my_putchar(i + '0');
      nb = nb - (a * i);
      a = a / base;
    }
}

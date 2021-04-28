/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/28 20:14:15 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/04/28 20:21:52 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		get_opposite(int trgb)
{
	int		t;
	int		r;
	int		g;
	int		b;
	int		trgb_ret;

	t = 0xFF - get_t(trgb);
	r = 0xFF - get_r(trgb);
	g = 0xFF - get_g(trgb);
	b = 0xFF - get_b(trgb);
	trgb_ret = create_trgb(t, r, g, b);
	return (trgb_ret);
}
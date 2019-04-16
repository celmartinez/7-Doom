/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:09:25 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 23:25:15 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		move_up4(t_struct *p, int move)
{
	if (move == 68)
	{
		system("killall afplay 2>&1");
		if (p->k == 0 && move == 68)
		{
			system("afplay ./doomzik/vivaldi_spring.mp3 & 2>&1");
			p->c->p_x = 1.5;
			p->k = 3;
		}
		else
		{
			p->k = 0;
			p->c->p_x = ((int)p->c->p_x == 13) ? 1.5 : 13.5;
			system("afplay ./doomzik/amblobby.mp3 & 2>&1");
		}
	}
	else if (move == 24 && p->k == 2)
		p->c->p_y -= 3;
}

static void		move_up3(t_struct *p, int move)
{
	if (move == 66)
	{
		system("killall afplay 2>&1");
		if (p->k == 0 && move == 66)
		{
			system("afplay ./doomzik/Doom_1.mp3 & 2>&1");
			p->c->p_x = 13.5;
			p->k = 4;
		}
		else
		{
			p->k = 0;
			p->c->p_x = ((int)p->c->p_x == 13) ? 1.5 : 13.5;
			system("afplay ./doomzik/amblobby.mp3 & 2>&1");
		}
	}
	else
		move_up4(p, move);
}

static void		movebobo(t_struct *p, int move)
{
	if (move == 12)
	{
		if (p->sound == 1)
		{
			system("killall afplay 2>&1");
			system("afplay ./doomzik/ambbobo.mp3 & 2>&1");
			if (p->k == 1)
			{
				system("killall afplay 2>&1");
				system("afplay ./doomzik/amblobby.mp3 & 2>&1");
			}
		}
		p->c->p_y = (p->k == 0) ? 1.5 : 13.5;
		p->k = (p->k == 0) ? 1 : 0;
	}
	else
		move_up3(p, move);
}

void			move_up2(t_struct *p, int move)
{
	if (move == 13)
	{
		if (p->sound == 1)
		{
			system("killall afplay 2>&1");
			system("afplay ./doomzik/lego.mp3 & 2>&1");
			if (p->k == 2)
			{
				system("killall afplay 2>&1");
				system("afplay ./doomzik/amblobby.mp3 & 2>&1");
			}
		}
		p->c->p_y = (p->k == 0) ? 13.5 : 1.5;
		p->k = (p->k == 0) ? 2 : 0;
	}
	else
		movebobo(p, move);
}

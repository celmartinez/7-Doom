/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:51:52 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/07 20:58:17 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			which_text(t_struct *p)
{
	if (p->map[p->k][p->c->map_x % 18][p->c->map_y % 18] > 1)
		p->tid = p->map[p->k][p->c->map_x % 18][p->c->map_y % 18];
	else if (p->map[p->k][p->c->map_x % 18][p->c->map_y % 18] == 1
			&& p->tid != 5)
	{
		if (p->c->side == 0 && p->c->r_dir_x > 0)
			p->tid = 9;
		else if (p->c->side == 0 && p->c->r_dir_x < 0)
			p->tid = 10;
		else if (p->c->side == 1 && p->c->r_dir_y > 0)
			p->tid = 11;
		else
			p->tid = 8;
	}
	if (p->k == 8 && p->tid == 5)
		p->tid = 18;
	else if (p->k == 0 && p->tid == 22 && p->elev == 0)
		p->tid = 117;
	else if (p->k == 2 && p->tid != 24 && p->tid != 13)
		p->tid = 23;
	else if (p->k == 7 && p->tid != 22)
		p->tid = 102;
	else if (p->k == 9 && p->tid != 22 && p->tid != 6)
		p->tid = 4;
}

void			which_textf(t_struct *p)
{
	p->tid = 7;
	if (p->k == 4)
		p->tid = p->floor;
	else if (p->k == 2 && p->tid != 24 && p->tid != 13)
		p->tid = 23;
	else if (p->k == 1)
		p->tid = 65;
	else if (p->k == 3)
		p->tid = 90;
	else if (p->k == 7)
		p->tid = 102;
	else if (p->k == 9 && p->tid != 6)
		p->tid = 4;
}

void			color_text2(t_struct *p, int col, int line, double ratio)
{
	ratio = 1 - ratio * 0.8;
	if (col + line + 3 < 262144)
	{
		p->color.r = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line]));
		p->color.g = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line + 1]));
		p->color.b = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line + 2]));
	}
}

void			color_text(t_struct *p, int col, int line, double ratio)
{
	if (p->hit == 2)
		which_text(p);
	col = col * BPP;
	line = line * 1024;
	ratio = 1 - ratio * 0.8;
	if (col + line + 3 < 262144)
	{
		p->color.r = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line]));
		p->color.g = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line + 1]));
		p->color.b = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line + 2]));
	}
}

void			color_textf(t_struct *p, int col, int line, double ratio)
{
	col = col * BPP;
	line = line * 1024;
	ratio = 1 - ratio * 0.8;
	if (col + line + 3 < 262144)
	{
		p->color.r = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line]));
		p->color.g = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line + 1]));
		p->color.b = (unsigned char)((ratio)
				* (unsigned char)(p->tex[p->tid].img_str[col + line + 2]));
	}
}

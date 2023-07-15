/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:17:19 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/15 11:58:07 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MLX_H
# define MINIRT_MLX_H

// X11 events
# define KeyPress 02
# define KeyRelease 03
# define ButtonPress 04
# define ButtonRelease 05
# define MotionNotify 06
# define EnterNotify 07
# define LeaveNotify 08
# define FocusIn 09
# define FocusOut 10
# define KeymapNotify 11
# define Expose 12
# define GraphicsExose 13
# define NoExpose 14
# define VisibilityNotify 15
# define CreateNotify 16
# define DestroyNotify 17
# define UnmapNotify 18
# define MapNotify 19
# define MapRequest 20
# define ReparentNotify 21
# define ConfigureNotify 22
# define ConfigureRequest 23
# define GravityNotify 24
# define ResizeRequest 25

// X11 masks
# define NoEventMask 0L
# define KeyPressMask (1L<<0)
# define KeyReleaseMask (1L<<1)
# define ButtonPressMask (1L<<2)
# define ButtonReleaseMask (1L<<3)
# define EnterWindowMask (1L<<4)
# define LeaveWindowMask (1L<<5)
# define PointerMotionMask (1L<<6)
# define PointerMotionHintMask (1L<<7)
# define Button1MotionMask (1L<<8)
# define Button2MotionMask (1L<<9)
# define Button3MotionMask (1L<<10)
# define Button4MotionMask (1L<<11)
# define Button5MotionMask (1L<<12)
# define ButtonMotionMask (1L<<13)
# define KeymapStateMask (1L<<14)
# define ExposureMask (1L<<15)
# define VisibilityChangeMask (1L<<16)
# define StructureNotifyMask (1L<<17)
# define ResizeRedirectMask (1L<<18)
# define SubstructureNotifyMask (1L<<19)
# define SubstructureRedirectMask (1L<<20)
# define FocusChangeMask (1L<<21)
# define PropertyChangeMask (1L<<22)
# define ColormapChangeMask (1L<<23)
# define OwnerGrabButtonMask (1L<<24)

# include "control.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

void	img_pix_put(t_img *img, int x, int y, int color);

#endif
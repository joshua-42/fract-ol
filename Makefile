# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 13:53:18 by jodougla          #+#    #+#              #
#    Updated: 2025/02/17 17:14:15 by jodougla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################################
#																	#
#		INGREDIENTS													#
#																	#
#####################################################################

NAME 			:= fractol

DIR_LIB			:= lib
DIR_HEADERS		:= headers
DIR_SRCS		:= srcs
DIR_OBJS		:= .objs

DIR_LIBFT		:= $(DIR_LIB)/libft
LIBFT_INCLUDES	:= $(DIR_LIBFT)/headers
DIR_MLX 		:= $(DIR_LIB)/MacroLibX
MLX_INCLUDES	:= $(DIR_MLX)/includes
MLX				:= $(DIR_MLX)/libmlx.so
LIBFT			:= $(DIR_LIBFT)/libft.a

SRCS	 		:=	main/main.c \
					mandelbrot/draw_mandelbrot.c \
					mandelbrot/prep_mandelbrot.c \
					julia/parsing_julia_arg.c \
					julia/prep_julia.c \
					julia/draw_julia.c \
					burningship/draw_burningship.c \
					burningship/prep_burningship.c \
					multibrot/draw_multibrot.c \
					multibrot/prep_multibrot.c \
					utils/write_error.c \
					utils/write_param.c \
					utils/set_env.c \
					utils/free_all.c \
					utils/set_mlx.c \
					utils/hook.c \
					utils/colors.c \
					utils/change_color.c \
					utils/zoom.c \
					utils/save.c \
					utils/hook2.c \

OBJS			:= $(addprefix $(DIR_OBJS)/, $(SRCS:%.c=%.o))

CC 				:= cc
CFLAGS 			:= -Wall -Werror -Wextra -g
IFLAGS			:= -I $(DIR_HEADERS)/ -I $(MLX_INCLUDES)/ -I $(LIBFT_INCLUDES)/

RM				:= rm -rf
DIR_DUP			:= mkdir -p $(@D)

define headers

███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗     
██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║     
█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║     
██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║     
██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝

endef
export headers

#####################################################################
#																	#
#		COLORS														#
#																	#
#####################################################################

RED		:=\033[0;31m
GREEN	:=\033[0;32m
NC		:=\033[0m
PURPLE 	:=\033[0;35m

#####################################################################
#																	#
#			RULES													#
#																	#
#####################################################################

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) -lm -lSDL2 $(OBJS) -o $(NAME) $(MLX) $(LIBFT)
	@clear
	@echo "$$headers"
	

$(MLX):
	$(MAKE) -C $(DIR_MLX) --no-print-directory -j

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT) --no-print-directory -j

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) $(DIR_OBJS)
	$(MAKE) -C $(DIR_MLX) clean
	$(MAKE) -C $(DIR_LIBFT) clean

fclean:clean
	@$(RM) $(NAME)
	$(MAKE) -C $(DIR_MLX) fclean
	$(MAKE) -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY : all clean fclean re

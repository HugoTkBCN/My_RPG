##
## EPITECH PROJECT, 2018
## makefile
## File description:
## .o
##

SRC	=	src/utils/my_putchar.c	\
		src/utils/my_putstr.c	\
		src/utils/my_put_nbr.c	\
		src/utils/my_strlen.c	\
		src/utils/my_strdup.c	\
		src/utils/my_strcpy.c	\
		src/utils/my_strncmp.c	\
		src/utils/convert.c	\
		src/utils/mem_alloc.c	\
		src/utils/get_file_in_array.c	\
		src/utils/my_revstr.c	\
		src/utils/free_array.c	\
		src/main.c	\
		src/window.c	\
		src/game_object.c	\
		src/my_rpg.c	\
		src/create_scene.c	\
		src/draw_scene.c	\
		src/move_char.c	\
		src/dialog.c	\
		src/particules.c	\
		src/framebuffer_create.c	\
		src/pause.c	\
		src/button.c	\
		src/destroy.c	\
		src/text.c	\
		src/menu.c	\
		src/fight/fight.c	\
		src/fight/pre_fight.c	\
		src/fight/disp_fight.c	\
		src/fight/create_attack.c	\
		src/fight/attacks.c	\
		src/parser/create/create_sprite_img.c	\
		src/parser/destroy/destroy_ennemies_pnj.c	\
		src/parser/destroy/destroy_game_obj_obstacle.c	\
		src/parser/destroy/destroy_image_sprite.c	\
		src/parser/destroy/destroy_scenes.c	\
		src/parser/destroy/destroy_sound_music_text.c	\
		src/parser/get/get_int.c	\
		src/parser/get/get_str.c	\
		src/parser/get/get_type_line.c	\
		src/parser/get/get_type_ennemy.c	\
		src/parser/get/get_only_scene_file.c	\
		src/parser/get/get_movements.c	\
		src/parser/get/get_name_file_in_dir.c \
		src/parser/run_line_parsing/parse_background.c	\
		src/parser/run_line_parsing/parse_obstacle.c	\
		src/parser/run_line_parsing/parse_game_object.c	\
		src/parser/run_line_parsing/parse_pnj.c	\
		src/parser/run_line_parsing/parse_ennemy.c	\
		src/parser/run_line_parsing/parse_music.c	\
		src/parser/run_line_parsing/parse_sound.c	\
		src/parser/run_line_parsing/parse_connection.c	\
		src/parser/utils/increase_i.c	\
		src/parser/utils/is_num.c	\
		src/parser/utils/str_to_low.c	\
		src/parser/utils/get_nbr_elem_in_file.c	\
		src/parser/utils/get_file_str.c	\
		src/parser/utils/is_scene_file.c	\
		src/parser/mallocs/run_mallocs.c	\
		src/parser/mallocs/malloc_ennemy_battle.c	\
		src/parser/mallocs/malloc_obstacle_game_obj.c	\
		src/parser/mallocs/malloc_pnj.c	\
		src/parser/mallocs/malloc_sound_music.c	\
		src/parser/run_parsing.c	\
		src/click_inventory.c	\
		src/inventory.c	\
		src/inventory_description.c	\
		src/inventory_object.c

NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

FLAGS =	-Wall -Werror -g3

LIB = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

HEAD	=	-I./include

all:	$(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC) $(LIB) $(FALGS) $(HEAD)

clean:
	@rm -rf $(OBJ)
fclean:		clean
	@rm -rf $(NAME)

re:	fclean all

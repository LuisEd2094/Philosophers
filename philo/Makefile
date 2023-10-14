NAME        = philo
CFLAGS      = -Wall -Wextra  -Werror -g #-fsanitize=thread #-fsanitize=address 
RM          = rm -f
CC			= cc
SRCS_PATH           = src/
OBJS_PATH           = obj/
ARGS_PATH			= ParseArguments/
PRG_PATH			= Program/
SHARED_PATH			=	SharedFiles/
MAKE_OBJ_DIR		= $(OBJS_PATH) $(addprefix $(OBJS_PATH), $(ARGS_PATH) \
						$(SHARED_PATH) $(PRG_PATH))
DEPS_PATH	= deps/
INCS        = -I./includes/

#Colors


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
LIGHT_GREEN = \033[1;92m

###

SRC         =	main.c 

ARGS		= 	print_err_args.c check_args.c remove_white_space.c \
				check_if_white_right_left.c	parse_arguments.c \
				remove_zeros.c

SHARED		=	ft_atoi.c ft_check_if_int.c ft_get_sign.c \
				ft_isspace.c ft_strlen.c ft_strcmp.c
PRG			=	init_prg.c close_prg.c \
				init_mutex.c one_philo_case.c get_time.c \
				routine.c actions.c print_philo_state.c \
				thread_handle_functions.c work_more_one_philo.c \
				supervisor.c

ARGS_FILES	=	$(addprefix $(ARGS_PATH), $(ARGS))

SHR_FILES	=	$(addprefix $(SHARED_PATH), $(SHARED))

PRG_FILES	=	$(addprefix $(PRG_PATH), $(PRG))

DEPS		= 	$(addprefix $(DEPS_PATH), $(SRC:.c=.d) $(ARGS:.c=.d) $(SHARED:.c=.d))

SRC			+=	$(ARGS_FILES) $(SHR_FILES) $(PRG_FILES)

OBJS        =	$(addprefix $(OBJS_PATH), $(SRC:.c=.o)) 
				

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c | $(MAKE_OBJ_DIR) $(DEPS_PATH)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCS) -MMD -MP -c $< -o $@ 
			@mv $(basename $@).d $(DEPS_PATH)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) -pthread -lpthread -o $(NAME) 
	@echo "$(LIGHT_GREEN)Created $(NAME) executable$(DEF_COLOR)"


$(MAKE_OBJ_DIR):
	@echo "$(GREEN)Creating $(NAME) Obj Dir $(DEF_COLOR)"
	@mkdir -p $(MAKE_OBJ_DIR)

$(DEPS_PATH):
	@echo "$(GREEN)Creating $(NAME) Deps Dir $(DEF_COLOR)"
	@mkdir -p $(DEPS_PATH)

-include $(DEPS)


clean: clean_objects

fclean:  clean_objects
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) executable cleaned!$(DEF_COLOR)"

clean_objects:
	@echo "$(GREEN)$(NAME) Objects and Dependencies cleaned!$(DEF_COLOR)"
	@$(RM) -r $(OBJS_PATH) $(DEPS_PATH)


re: fclean all 

.PHONY: all fclean clean re 

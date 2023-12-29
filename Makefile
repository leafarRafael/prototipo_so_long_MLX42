NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= /nfs/homes/rbutzke/projetos/prototipos_projetos/so_long/lib/lib_get_print/libft.a
PATH_MAKE_LIB:= /nfs/homes/rbutzke/projetos/prototipos_projetos/so_long/lib/lib_get_print

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

$(NAME):$(LIBFT)

$(LIBFT): $(PATH_MAKE_LIB)/Makefile
	$(MAKE) -C $(PATH_MAKE_LIB)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

libft_clean:
	$(MAKE) -C $(PATH_MAKE_LIB) fclean

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean libft_clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
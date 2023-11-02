SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c
SRCS_COMMON	= commons.c
SERVER		= server
CLIENT		= client
LIBFT		= libft/lib/libft.a
LIBFT_NAME	= ft
LIBFT_DIR	= libft
LIBFT_A_DIR	= libft/lib
LIBFT_I_DIR	= libft/include
LDFLAGS		= -fuse-ld=lld

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT)
	gcc $(LDFLAGS) -L$(LIBFT_A_DIR) -l$(LIBFT_NAME) -I$(LIBFT_I_DIR) $(SRCS_COMMON) $(SRCS_SERVER) -o $(SERVER)

$(CLIENT): $(LIBFT)
	gcc $(LDFLAGS) -L$(LIBFT_A_DIR) -l$(LIBFT_NAME) -I$(LIBFT_I_DIR) $(SRCS_COMMON) $(SRCS_CLIENT) -o $(CLIENT)

$(LIBFT):
	make --directory $(LIBFT_DIR) 

clean:
	make --directory $(LIBFT_DIR) fclean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

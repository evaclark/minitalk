CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(PRINTF) -L $(PRINTF) -l $(LIB)
RM = rm -f

PRINTF = ft_printf
LIB = ftprintf
SERVER = server
CLIENT = client

all:
	@make -s -C $(PRINTF)
	$(CC) $(CFLAGS) server.c -o $(SERVER)
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

clean:
	@make clean -s -C $(PRINTF)

fclean:
	@make fclean -s -C $(PRINTF)
	$(RM) $(SERVER) $(CLIENT)

re: all fclean

.PHONY: all clean fclean re

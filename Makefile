# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:13:06 by moel-oua          #+#    #+#              #
#    Updated: 2025/02/20 09:42:33 by moel-oua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS_SERVER_bonus = bonus/server_bonus.c bonus/utils_bonus.c 
SRCS_CLIENT_bonus = bonus/client_bonus.c bonus/utils_bonus.c
HEADER_BONUS = ./bonus/minitalk_bonus.h
OBJS_SERVER_bonus = $(SRCS_SERVER_bonus:.c=.o)
OBJS_CLIENT_bonus = $(SRCS_CLIENT_bonus:.c=.o)
SERVER_bonus = server_bonus
CLIENT_bonus = client_bonus

SERVER = server
CLIENT = client
SRCS_SERVER = mandatory/server.c mandatory/utils.c 
SRCS_CLIENT = mandatory/client.c mandatory/utils.c
HEADER = minitalk.h
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT) 

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)


$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)

mandatory/%.o : mandatory/%.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o $@

bonus: $(SERVER_bonus) $(CLIENT_bonus)

$(SERVER_bonus): $(OBJS_SERVER_bonus) 
	$(CC) $(CFLAGS) $(OBJS_SERVER_bonus) -o $(SERVER_bonus)

$(CLIENT_bonus): $(OBJS_CLIENT_bonus) 
	$(CC) $(CFLAGS) $(OBJS_CLIENT_bonus) -o $(CLIENT_bonus)
	

bonus/%.o: bonus/%.c $(HEADER_BONUS)
	${CC} ${CFLAGS} -c $< -o $@


clean:	
	rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_bonus} ${OBJS_CLIENT_bonus}


fclean:	clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_bonus) $(CLIENT_bonus)
 
re:	fclean all
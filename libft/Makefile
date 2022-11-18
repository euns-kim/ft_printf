NAME = libft.a
SOURCE = ft_atoi.c \
ft_calloc.c \
ft_isalpha.c \
ft_isdigit.c \
ft_memchr.c \
ft_memcpy.c \
ft_memset.c \
ft_strdup.c \
ft_strlcpy.c \
ft_strncmp.c \
ft_strrchr.c \
ft_toupper.c \
ft_bzero.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_memcmp.c \
ft_memmove.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlen.c \
ft_strnstr.c \
ft_tolower.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

SOURCE_BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJECT = $(SOURCE:.c=.o)
OBJECT_BONUS = $(SOURCE_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $?

$(OBJECT) : $(SOURCE)
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECT) $(OBJECT_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECT_BONUS)
	ar -rcs $(NAME) $?

$(OBJECT_BONUS) : $(SOURCE_BONUS)
	$(CC) -c $(CFLAGS) $?

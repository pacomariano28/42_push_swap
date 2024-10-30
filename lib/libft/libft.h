/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:34:30 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/03 12:24:53 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

/**
 * @brief check if param is a letter
 * 
 * @param c 
 * @return int / 1 - true / 0 - false
 */
int		ft_isalpha(int c);
/**
 * @brief check if param is a num
 * 
 * @param c 
 * @return int / 1 - true / 0 - false
 */
int		ft_isdigit(int c);
/**
 * @brief check if param is alphanum
 * 
 * @param c 
 * @return int / 1 - true / 0 - false
 */
int		ft_isalnum(int c);
/**
 * @brief checks if param is an ascii character
 * 
 * @param c 
 * @return int / 1 - true / 0 - false
 */
int		ft_isascii(int c);
/**
 * @brief check if param is printable
 * 
 * @param c 
 * @return int / 1 - true / 0 - false
 */
int		ft_isprint(int c);
/**
 * @brief return lenght of the string
 * 
 * @param str 
 * @return int
 */
int		ft_strlen(const char *str);
/**
 * @brief replaces the data from the memory bytes to 0. Starts on s position
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief copy src in dst. Take the full size of the destination buffer and 
 * guarantee NUL-termination if there is room 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t - lenght of the string created 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @brief appends src in dst. Take the full size of the destination buffer and 
 * guarantee NUL-termination if there is room 
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/**
 * @brief turns uppercase the param and returns it
 * 
 * @param c 
 * @return int 
 */
int		ft_toupper(int c);
/**
 * @brief turns lowercase the param and returns it
 * 
 * @param c 
 * @return int 
 */
int		ft_tolower(int c);
/**
 * @brief locates the first occurence of c
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief locates the last occurence of c
 * 
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief compare the strings
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int
 * s1 > s2 				-> 1
 * s2 > s1 || s2 == s1 	-> 0
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief locates the first occurrence of c 
 * (converted to an unsigned char) 
 * 
 * @param str 
 * @param c 
 * @param n 
 * @return a pointer to the byte located, 
 * or NULL if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *str, int c, size_t n);
/**
 * @brief writes len bytes of value c 
 * (converted to an unsigned char) to the string b
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void	*ft_memset(void *b, int c, size_t len);
/**
 * @brief copies n bytes from memory area src to memory area dst
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief returns zero if the two strings are identical, 
 * otherwise returns the difference between the first two differing bytes
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief both strings (src and dst) can overlap in memory and 
 * this function does not overwrite part of, or the entirety 
 * of the string when making the copy.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief locates the first occurrence of the null-terminated 
 * string needle in the string haystack, where not more than len
 * characters are searched.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @brief converts the initial portion of the string pointed 
 * to by str to int representation.
 * 
 * @param str 
 * @return int 
 */
int		ft_atoi(const char *str);
/**
 * @brief sets all the memory bytes are set to 0
 *
 * @param count 
 * @param size sizeof(type)
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size);
/**
 * @brief allocates sufficient memory for a copy of the string s1, 
 * does the copy, and returns a pointer to it.  The
 * pointer may subsequently be used as an argument to the function free(3).
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1);
/**
 * @brief Take two strings as arguments and create a new string 
 * that is the concatenation of both. Memory is dynamically allocated 
 * for the resulting string, and you must free it with free when
 * you no longer need it.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief returns a substring of the string s passed as parameter.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief deletes the first and last occurences of set chars in s1
 * when other char is detected, it stops looking for occurences.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief int to ascii
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n);
/**
 * @brief reads the given file and breaks it up into files of 1000 lines each.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(const char *s, char c);
/**
 * @brief takes two parameters, the first one is a string, 
 * and the second one is a function.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief apply the function f to every character of the string s.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief writes the character c on the file descriptor fd.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief writes the string str on the file descriptor fd.
 * 
 * @param str 
 * @param fd 
 */
void	ft_putstr_fd(char *str, int fd);
/**
 * @brief works the same way as ft_putstr_fd
 * , it just adds a newline character at the end.
 * 
 * @param str 
 * @param fd 
 */
void	ft_putendl_fd(char *str, int fd);
/**
 * @brief put a number in a fd file
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Create a new node using malloc(3).
 *  The member variable 'content' is initialized with the content
 *  of the 'content' parameter. The 'next' variable is initialized with NULL
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Add the 'new' element at the front of the list
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief returns the len of the list
 * 
 * @param lst 
 * @return int 
 */
int		ft_lstsize(t_list *lst);
/**
 * @brief return last node of the list
 * 
 * @param lst 
 * @return t_list* 
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief adds new node to the last position of the list
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief free memory of lst -> content with f(*del) param,
 * also free(lst). 
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/**
 * @brief deletes and free all lst nodes with del() and free()
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * @brief moves on the list and applies f() to each content
 * 
 * @param lst 
 * @param f 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief 
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
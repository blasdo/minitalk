/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:54:00 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/01 15:09:09 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

// Most frecuently Bases
# define LOW_HEX "0123456789abcdef"
# define UPP_HEX "0123456789ABCDEF"
# define DEC "0123456789"
// Structs
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;
typedef struct s_bufflist
{
	int					readrtn;
	char				buff[BUFFER_SIZE];
	struct s_bufflist	*next;
}				t_bufflist;
// Pseudooolean type Functions (is_x)
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
// Casting Functions
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_ltoa_base(long long lnbr, char *base);
char		*ft_ultoa_base(unsigned long lnbr, char *base);
// Cleaning Strings and Memory Functions
char		*ft_strtrim(char const *s1, char const *set);
// Char transformation Functions
int			ft_tolower(int c);
int			ft_toupper(int c);
// Copy, concat and split Fuctions
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
// Fuctions Pointers Functions
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
// Info Functions
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_numlen_base(long long lnbr, long long base_len);
size_t		ft_unumlen_base(unsigned long lnbr, unsigned long base_len);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// Inicialization Functions
void		*ft_bzero(void *b, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
//List Funcions
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
// Put_x_fd Functions
void		ft_putchar_fd(char c, int fd);
int			ft_putptr_fd(void *ptr, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putlnbr_base_fd(long long nbr, char *base, int fd);
int			ft_putulnbr_base_fd(unsigned long nbr, char *base, int fd);
// Search Char or String in Memory or Null terminated Strings Functions
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
// Added Functions
//  ft_printf
int			ft_printf(char const *format, ...);
int			ft_fdprintf(int fd, char const *format, ...);
//  get_next_line
char		*get_next_line(int fd);
t_bufflist	*newbuff(t_bufflist *list, int fd);
size_t		char_count_buff(t_bufflist *first);
char		*bufflist_to_str(t_bufflist *first);
void		*freebuff(t_bufflist **bufflist);
void		clearbuff(t_bufflist **bufflist);
char		*findnl(t_bufflist *arr);
//  sort functions
int			issorted_int(int *numbers, size_t len);
void		bubblesort_int(int *numbers, size_t len);
#endif

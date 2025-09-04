#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

#define RESET "\033[0m"

#define RED "\033[31m\033[1m"
#define BLUE "\033[34m\033[1m"
#define CYAN "\033[36m\033[1m"
#define GREEN "\033[32m\033[1m"
#define YELLOW "\033[33m\033[1m"
#define MAGENTA "\033[95m\033[1m"

extern char *ft_strdup(const char *str);
extern unsigned long ft_strlen(char const *s1);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(char const *s1, char const *s2);
extern ssize_t ft_read(int fd, void *src, size_t size);
extern ssize_t ft_write(int fd, const void *src, size_t size);

void test_read();
void test_write();
void test_strcpy();
void test_strcmp();
void test_strdup();
void test_strlen();

#!/bin/bash

make
clang -Wall -Wextra -Werror main.c libft.a

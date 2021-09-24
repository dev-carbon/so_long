#!/bin/bash

make re
clang -Wall -Wextra -Werror -g main.c libft.a


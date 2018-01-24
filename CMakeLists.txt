cmake_minimum_required(VERSION 3.9)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")
include_directories(
        includes
) # header directories
#target_include_directories(includes)
link_directories(
        libft
#        includes
) # library directories
set(SOURCE_FILES
        main.c
        sources/ft_printf.c includes/ft_printf.h sources/pf_c.c sources/ft_itoabase.c sources/pf_undefined.c sources/pf_flags.c sources/ft_strjoinandfree.c sources/ft_flist_set.c) # sources
add_executable(ft_printf ${SOURCE_FILES}) # compilation
target_link_libraries(ft_printf -lft) # linkage
target_link_libraries(ft_printf ${CMAKE_SOURCE_DIR}/libft/libft.a)

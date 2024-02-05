cmake_minimum_required(VERSION 3.25)
project(AS_TNV_PROJECT C)

set(CMAKE_C_STANDARD 90)

add_executable(AS_TNV_PROJECT main.c "as_library0.c" "as_library0.h" as_library1.c as_library1.h as_library2_a.c as_library2_a.h as_library2_b.c as_library2_c.c as_library2_c.h as_library2_b.h as_library3.c as_library3.h as_library4.c as_library4.h)


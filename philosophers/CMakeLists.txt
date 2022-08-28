cmake_minimum_required(VERSION 3.23)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(philo)

add_executable(philosophers
        philo/philo_behaviours.c
        philo/philo_check.c
        philo/philo_tools.c
        philo/philo_utils.c
        philo/philosophers.c
        philo/philosophers.h)

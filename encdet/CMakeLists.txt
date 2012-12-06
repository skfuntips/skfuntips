project (encdet)

include_directories(include)

add_subdirectory(src)

add_executable(encdet_cli encdet.c)

target_link_libraries(encdet_cli encdet)

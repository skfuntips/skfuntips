add_executable(to_tl to_tl.cpp)
target_link_libraries(to_tl ${QT_LIBRARIES})

add_executable(so so.cpp)
target_link_libraries(so isp ${QT_LIBRARIES})



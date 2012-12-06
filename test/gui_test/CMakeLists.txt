
get_target_property(incs kongJian INCLUDE_DIRECTORIES)

include_directories(${incs} 
     ${CMAKE_CURRENT_BINARY_DIR})

 function(add_kong_jian_test bareFileName)

     add_executable(${bareFileName} ${bareFileName}.cpp)
     target_link_libraries(${bareFileName} kongJian isp ${QT_LIBRARIES})

 endfunction()

add_kong_jian_test(shu_ru_kong_jian_ce_shi)
add_kong_jian_test(zhong_zi_kong_jian_ce_shi)
add_kong_jian_test(zheng_shu_fan_wei_kong_jian_ce_shi)
add_kong_jian_test(zi_ti_kong_jian_ce_shi)


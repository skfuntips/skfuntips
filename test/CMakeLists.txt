
add_library(test_function test_function.cpp)

function(pui_test_add filename)
    add_executable(${filename} ${filename}.cpp)

    target_link_libraries(${filename} test_function isp ${QT_LIBRARIES})


    if(DEFINED ARGV1)
        add_test(test_${filename} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename})
    else()

        get_filename_component(tst ${CMAKE_CURRENT_SOURCE_DIR}/${filename}.txt
            ABSOLUTE)
       if(EXISTS ${tst})
       else()
	    message(FATAL_ERROR "input test file \"${tst}\" not exists")
       endif()

       add_test(test_${filename} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename} ${tst})
    endif()

    set_tests_properties(test_${filename} PROPERTIES
       TIMEOUT 10)

endfunction()

pui_test_add(zheng_ze_ce_shi FALSE)
pui_test_add(zhong_zi_ce_shi)
pui_test_add(zheng_shu_fan_wei_ce_shi FALSE)
pui_test_add(qu_chu_huan_hang_ce_shi)
pui_test_add(hang_duan_kai_ce_shi FALSE)

add_executable(all_cli all_cli.cpp)
target_link_libraries(all_cli test_function isp ${QT_LIBRARIES})

add_executable(gif_bao_cun_ce_shi gif_bao_cun_ce_shi.cpp)
target_link_libraries(gif_bao_cun_ce_shi isp ${QT_LIBRARIES})
add_test(ce_shi_gif_bao_cun ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/gif_bao_cun_ce_shi)


add_subdirectory(gui_test)



foreach(inputVar ge_ci_1.txt 
        #ke_wen_1.txt 
        #er_ge_1.txt
        xin_wen_1.txt)
        
    file(COPY ${inputVar} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

    foreach(fangFaVar 
            ToBigCharProcessor PinYinProcessor
            ToImageProcessor InsertProcessor
            ToGifProcessor ReverseProcessor
            ShuffleProcessor AverageInsertProcessor
            SimilarProcessor VerticalLayoutProcessor
            EncryptProcessor OffsetProcessor
            )


        add_test(
            NAME test_${fangFaVar}_${inputVar}
            WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
            COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/all_cli 
            ${fangFaVar} ${inputVar}
            )

    endforeach(fangFaVar)

endforeach(inputVar)


add_executable(unicode_test unicode_test.cpp)
target_link_libraries(unicode_test ${QT_LIBRARIES})

add_executable(encrypt_process_test encrypt_process_test.cpp)
target_link_libraries(encrypt_process_test isp ${QT_LIBRARIES})
add_test(test_encrypt_process ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/encrypt_process_test)


add_executable(offset_process_test offset_process_test.cpp)
target_link_libraries(offset_process_test isp ${QT_LIBRARIES})
add_test(test_offset_process ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/offset_process_test)

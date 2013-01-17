
set(uiFiles "")
set(srcs "")
set(headers "")

foreach(fileVar ResultWidget SourceWidget 
        FontWidget SeedWidget
         IntRangeWidget MainFrame
         ParamListWidget ProcessWidget
         CompositeResourceWidget
         StringWidget ImageListWidget
         ImagePreviewDialog
        )

     list(APPEND uiFiles ${fileVar}.ui)
     list(APPEND srcs ${fileVar}.cpp)
     list(APPEND headers ${fileVar}.h)

endforeach(fileVar)

 list(APPEND uiFiles AboutDialog.ui)
 list(APPEND srcs ProcessThread.h gongJu.cpp ParamWidget.cpp)

qt4_wrap_ui(uis ${uiFiles})

foreach(rel IN LISTS srcs uiFiles)
    get_filename_component(abs_path ${rel}
        ABSOLUTE)

    list(APPEND abs_srcs ${abs_path})

endforeach(rel)

set (FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${abs_srcs} PARENT_SCOPE)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(kongJian ${uis} ${headers} ${srcs}  )

target_link_libraries(kongJian isp)

set_target_properties(kongJian PROPERTIES AUTOMOC TRUE)

set(gui_SOURCE main.cpp)


 IF( MINGW )
    # resource compilation for MinGW
    ADD_CUSTOM_COMMAND( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/tuBiao.o
                        COMMAND windres.exe -I${CMAKE_CURRENT_SOURCE_DIR} -i${CMAKE_CURRENT_SOURCE_DIR}/../tuBiao.rc
                             -o ${CMAKE_CURRENT_BINARY_DIR}/tuBiao.o )
    LIST(APPEND gui_SOURCE main.cpp ${CMAKE_CURRENT_BINARY_DIR}/tuBiao.o)
  ELSE( MINGW )
    LIST(APPEND gui_SOURCE main.cpp)
  ENDIF( MINGW )


add_executable(gui WIN32 ${gui_SOURCE} ${QM_FILES})

target_link_libraries(gui kongJian ${QT_LIBRARIES})


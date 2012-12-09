project(textprocess)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


find_package(Qt4 REQUIRED)
find_package(Boost REQUIRED)

set(CMAKE_AUTOMOC ON)

include(${QT_USE_FILE})


include_directories( ${QT_INCLUDES} giflib)
include_directories(
    ${Boost_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/param
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Processor)


enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (FILES_TO_TRANSLATE )


add_subdirectory(giflib)
add_subdirectory(encdet)
add_subdirectory(src)
add_subdirectory(util)


add_subdirectory(test)

set (TRANSLATIONS_FILES i18n/zh_CN.ts)


option (UPDATE_TRANS "Update source translation translations/*.ts
files (WARNING: make clean will delete the source .ts files! Danger!)")
if (UPDATE_TRANS)
  qt4_create_translation(QM_FILES ${FILES_TO_TRANSLATE} ${TRANSLATIONS_FILES})
else (UPDATE_TRANS)
  qt4_add_translation(QM_FILES ${TRANSLATIONS_FILES})
endif (UPDATE_TRANS)


add_custom_target (trans_target DEPENDS ${QM_FILES})

install(FILES ${QM_FILES} DESTINATION
${CMAKE_INSTALL_PREFIX}/translations)

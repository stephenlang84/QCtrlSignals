cmake_minimum_required(VERSION 3.5)

project(qctrlsignals)

find_package(Qt6 COMPONENTS Core REQUIRED)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/QCtrlSignals
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler_p.h
)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler.cpp
)

if(WIN32)
    list(APPEND HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler_win.h)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler_win.cpp)
elseif(UNIX)
    list(APPEND HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler_unix.h)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/qctrlsignalhandler_unix.cpp)
endif()

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Core)

target_compile_definitions(${PROJECT_NAME} PRIVATE Q_CTRL_SIGNALS_EXPORT=)

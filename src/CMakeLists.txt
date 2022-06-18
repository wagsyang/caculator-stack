find_package(Qt5 COMPONENTS Core Gui Quick REQUIRED)

# generate lib for test
add_library(expression STATIC expression.cpp)
target_include_directories(expression PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
        expression 
    PUBLIC 
        Qt5::Core 
        Qt5::Gui 
        Qt5::Quick
)

# generate target
set (SRCS
    main.cpp
    midlayer.h
    midlayer.cpp
    qml.qrc
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
        ${CMAKE_PROJECT_NAME}  
    PRIVATE 
        Qt5::Core 
        Qt5::Gui 
        Qt5::Quick 
        expression
)


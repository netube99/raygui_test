cmake_minimum_required(VERSION 3.2)
project(raylib_test)

# 添加源文件
file(GLOB USER_SOURCES user/*.c)

# 添加可执行目标
add_executable(${PROJECT_NAME}
    ${USER_SOURCES}
)

# 查找 raylib 库
find_package(raylib REQUIRED)

# 添加 raygui 头文件目录
target_include_directories(${PROJECT_NAME}
    PRIVATE
    user
    ${raylib_INCLUDE_DIRS}
    lib
)

# 链接 raylib 和 raygui 库
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    pthread
    ${raylib_LIBRARIES}
    m
)

# cmake安装规则
install(TARGETS ${PROJECT_NAME}
    DESTINATION /usr/bin
)

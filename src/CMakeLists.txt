cmake_minimum_required(VERSION 3.10)
project(TopSystems)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
set(SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        third_party/imgui/imgui.cpp
        third_party/imgui/imgui_widgets.cpp
        third_party/imgui/imgui_tables.cpp
        third_party/imgui/imgui_draw.cpp
        third_party/imgui/imgui_demo.cpp
        third_party/imgui/backends/imgui_impl_glfw.cpp
        third_party/imgui/backends/imgui_impl_opengl3.cpp
        controller/controller.cpp controller/controller.h model/components/object.cpp model/components/object.h model/components/figure.cpp model/components/figure.h model/components/figures/square.cpp model/components/figures/square.h model/components/figures/triangle.cpp model/components/figures/triangle.h model/components/figures/circle.cpp model/components/figures/circle.h model/model.cpp model/model.h model/components/grid.cpp model/components/grid.h model/components/grid.cpp view/user_interface.cpp view/user_interface.h view/window.cpp view/window.h model/input_controller.cpp model/input_controller.h)

# Дополнительные пути для заголовочных файлов
include_directories(
        third_party/imgui
        third_party/imgui/backends
        third_party/glfw/include
        third_party/glfw/include/GLFW
)

# Библиотеки и флаги линковки
set(GLFW_LIB_DIR third_party/glfw/lib-mingw-w64)
set(LIBS glfw3 gdi32 opengl32)
link_directories(${GLFW_LIB_DIR})

# Имя исполняемого файла
set(TARGET TopSystems)

# Создание исполняемого файла
add_executable(${TARGET} ${SRCS})

# Линковка библиотек
target_link_libraries(${TARGET} ${LIBS})

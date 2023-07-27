# CMakeList.txt : CMake project for game, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (game "Game.cpp" "Game.h" "Texture.cpp" "Texture.h"  "main.cpp" "main.h" "IUpdateable.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET game PROPERTY CXX_STANDARD 20)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
target_link_libraries(game SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)
# TODO: Add tests and install targets if needed.

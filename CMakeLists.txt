cmake_minimum_required(VERSION 3.21)
project(AutoSob LANGUAGES CXX)

find_package(Slint QUIET)
find_package(CURL 7.86 REQUIRED)
find_package(nlohmann_json REQUIRED)
if (NOT Slint_FOUND)
  message("Slint could not be located in the CMake module search path. Downloading it from Git and building it locally")
  include(FetchContent)
  FetchContent_Declare(
    Slint
    GIT_REPOSITORY https://github.com/slint-ui/slint.git
    # `release/1` will auto-upgrade to the latest Slint >= 1.0.0 and < 2.0.0
    # `release/1.0` will auto-upgrade to the latest Slint >= 1.0.0 and < 1.1.0
    GIT_TAG release/1
    SOURCE_SUBDIR api/cpp
  )
  FetchContent_MakeAvailable(Slint)
endif (NOT Slint_FOUND)

if(ANDROID)
    add_library(AutoSob SHARED src/main.cpp src/discord.cpp)
else()
    add_executable(AutoSob src/main.cpp src/discord.cpp)
endif()
target_link_libraries(AutoSob PRIVATE CURL::libcurl nlohmann_json::nlohmann_json Slint::Slint)
slint_target_sources(AutoSob ui/app-window.slint)
# On Windows, copy the Slint DLL next to the application binary so that it's found.
if (WIN32)
    add_custom_command(TARGET AutoSob POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:AutoSob> $<TARGET_FILE_DIR:AutoSob> COMMAND_EXPAND_LISTS)
endif()

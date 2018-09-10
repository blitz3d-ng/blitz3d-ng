cmake_minimum_required (VERSION 3.0)
project (Blitz3D)

include(src/bin2h.cmake)

IF(NOT BB_PLATFORM)
  IF(WIN32)
    IF(CMAKE_SIZEOF_VOID_P EQUAL 8)
      set (BB_PLATFORM win64)
    ELSEIF(CMAKE_SIZEOF_VOID_P EQUAL 4)
      set (BB_PLATFORM win32)
    ENDIF()
  ELSEIF(APPLE)
    set (BB_PLATFORM macos)
  ELSEIF(UNIX)
    set (BB_PLATFORM linux)
  ENDIF()
ENDIF()

IF(BB_PLATFORM MATCHES win32)
  set (BB_WIN32 true)
  set (BB_MSVC true)
  add_definitions(-DBB_WIN32)
ELSEIF(BB_PLATFORM MATCHES win64)
  set (BB_WIN64 true)
  set (BB_MSVC true)
  add_definitions(-DBB_WIN64)
ELSEIF(BB_PLATFORM MATCHES mingw32)
  set (BB_MINGW32 true)
  add_definitions(-DBB_MINGW32)
ELSEIF(BB_PLATFORM MATCHES macos)
  set (BB_MACOS true)
  add_definitions(-DBB_MACOS)
ELSEIF(BB_PLATFORM MATCHES linux)
  set (BB_LINUX true)
  add_definitions(-DBB_LINUX)
ELSEIF(BB_PLATFORM MATCHES ios)
  set (BB_IOS true)
  add_definitions(-DBB_IOS)
ELSEIF(BB_PLATFORM MATCHES android)
  set (BB_ANDROID true)
  add_definitions(-DBB_ANDROID)
ELSEIF(BB_PLATFORM MATCHES emscripten)
  set (BB_EMSCRIPTEN true)
  add_definitions(-DBB_EMSCRIPTEN)
ENDIF()

IF(BB_WIN32 OR BB_WIN64 OR BB_MINGW32)
  set (BB_WINDOWS true)
  add_definitions(-DBB_WINDOWS)

  link_directories(common/x86)
ENDIF()

IF(BB_WINDOWS OR BB_MACOS OR BB_LINUX)
  set (BB_DESKTOP true)
  add_definitions(-DBB_DESKTOP)
ENDIF()

IF(BB_IOS OR BB_ANDROID)
  set (BB_MOBILE true)
  add_definitions(-DBB_MOBILE)
ENDIF()

IF(NOT BB_ENV)
  set (BB_ENV debug)
ENDIF()

IF(BB_ENV MATCHES debug OR BB_ENV MATCHES test)
  set (CMAKE_BUILD_TYPE Debug)
  set (BB_DEBUG true)

  # TODO: work to remove the need for this...
  add_definitions(-D_DEBUG)
ELSE()
  set (CMAKE_BUILD_TYPE Release)
  set (BB_RELEASE true)
ENDIF()

if(BB_ENV MATCHES test)
  set(BB_COVERAGE "-fprofile-arcs -ftest-coverage")
endif()

set (CMAKE_POSITION_INDEPENDENT_CODE ON)

set (BUILD_PATH ${CMAKE_SOURCE_DIR}/_release/toolchains/${BB_PLATFORM})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_PATH}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_PATH}/lib/${BB_ENV})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_PATH}/lib/${BB_ENV})

# TODO: move these to their appropriate modules
add_definitions(-DPRO -DFREEIMAGE_LIB -DOPJ_STATIC -D_CRT_SECURE_NO_WARNINGS -DDIRECTSOUND_VERSION=0x700 -DODE_LIB)

add_definitions(-DBB_PLATFORM="${BB_PLATFORM}")
add_definitions(-DBB_ENV="${BB_ENV}")


IF(BB_MSVC)
  IF(BB_DEBUG)
    add_definitions(/MTd)
  ELSE()
    add_definitions(/MT)
  ENDIF()
ENDIF()

add_subdirectory(stdutil)

IF(BB_WIN32 OR BB_WIN64)
  add_subdirectory(blitzide)
ENDIF()

IF(BB_DESKTOP OR BB_EMSCRIPTEN)
  add_subdirectory(compiler)
ENDIF()

IF(BB_WINDOWS)
  add_subdirectory(linker)
ENDIF()

IF(NOT BB_IOS)
  add_subdirectory(src/deps/zlib)
  set(ZLIB zlibstatic)
ELSE()
  set(ZLIB z)
ENDIF()

add_subdirectory(src/deps/assimp)
add_subdirectory(src/deps/crossguid)
add_subdirectory(src/deps/enet/src)
add_subdirectory(src/deps/freetype2)
add_subdirectory(src/deps/glew)
add_subdirectory(src/deps/ogg)
add_subdirectory(src/deps/vorbis)

add_subdirectory(src/modules)
add_subdirectory(src/runtime)

IF(BB_DESKTOP)
  add_subdirectory(src/deps/freeimage317)
  add_subdirectory(src/deps/glfw3)
  add_subdirectory(src/deps/ode)
ELSEIF(BB_IOS OR BB_ANDROID)
  add_subdirectory(src/deps/glfm)
ENDIF()
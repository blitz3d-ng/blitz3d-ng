set (CMAKE_CXX_STANDARD 11)

add_library(crossguid STATIC src/guid.h src/guid.cpp)
target_include_directories(crossguid SYSTEM PUBLIC src)

IF(BB_WINDOWS)
  target_compile_definitions(crossguid PRIVATE -DGUID_WINDOWS)
ELSEIF(BB_MACOS)
  target_compile_definitions(crossguid PRIVATE -DGUID_CFUUID)
  target_link_libraries(crossguid "-framework CoreFoundation")
ELSEIF(BB_LINUX)
  target_compile_definitions(crossguid PRIVATE -DGUID_LIBUUID)
ENDIF()

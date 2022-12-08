# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_enable_cxx17.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_add_subdirectory.cmake")

# Мета-информация о проекте
set(META_GAPI_DUMMY_PRJNAME "module_gapi_dummy")
set(META_GAPI_DUMMY_LIBNAME "lib${META_GAPI_DUMMY_PRJNAME}")
set(META_GAPI_DUMMY_LANGUAGES CXX)
set(META_GAPI_DUMMY_VERSION_MAJOR 0)
set(META_GAPI_DUMMY_VERSION_MINOR 2)
set(META_GAPI_DUMMY_VERSION_PATCH 0)
set(META_GAPI_DUMMY_VERSION ${META_GAPI_DUMMY_VERSION_MAJOR}.${META_GAPI_DUMMY_VERSION_MINOR}.${META_GAPI_DUMMY_VERSION_PATCH})

# Опции сборки
option(MODULE_GAPI_BUILD_SHARED "Build shared library" OFF)
option(ENABLE_COVERAGE "Enable coverage builds" OFF)
option(ENABLE_TESTS "Enable test builds" OFF)
option(ENABLE_EXAMPLES "Enable example builds" OFF)

project(${META_GAPI_DUMMY_PRJNAME} VERSION ${META_GAPI_DUMMY_VERSION} LANGUAGES ${META_GAPI_DUMMY_LANGUAGES})

# Подмодули
custom_add_subdirectory("libmodule_core" submodules/sway.module_core)

if (ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif ()

# Определяем каталог вывода по умолчанию
if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
else ()
  set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
endif ()

set(MODULE_GAPI_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${MODULE_GAPI_DIR}/include")
include_directories("${MODULE_GAPI_DIR}/submodules/sway.module_core/lib/include")
include_directories("${MODULE_GAPI_DIR}/submodules/sway.module_math/lib/include")
include_directories("${MODULE_GAPI_DIR}/submodules/sway.module_gapi/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_GAPI_HEADERS "${MODULE_GAPI_DIR}/include/*.*")
file(GLOB_RECURSE MODULE_GAPI_SOURCES "${MODULE_GAPI_DIR}/src/*.*")

if (MODULE_GAPI_BUILD_SHARED)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fPIE")

  # Добавляем в проект цель для сборки динамической библиотеки
  add_library(${META_GAPI_DUMMY_LIBNAME} SHARED ${MODULE_GAPI_SOURCES})
  set_target_properties(${META_GAPI_DUMMY_LIBNAME} PROPERTIES OUTPUT_NAME ${META_GAPI_DUMMY_PRJNAME})
  set_target_properties(${META_GAPI_DUMMY_LIBNAME} PROPERTIES PREFIX "")
  set_target_properties(${META_GAPI_DUMMY_LIBNAME} PROPERTIES SUFFIX ".so.${META_GAPI_DUMMY_VERSION}")
  target_compile_definitions(${META_GAPI_DUMMY_LIBNAME} PRIVATE -DBUILD_DLLAPI_LIBMODULE)
else ()
  # Добавляем в проект цель для сборки статической библиотеки
  add_library(${META_GAPI_DUMMY_LIBNAME} STATIC ${MODULE_GAPI_SOURCES})
  set_target_properties(${META_GAPI_DUMMY_LIBNAME} PROPERTIES OUTPUT_NAME ${META_GAPI_DUMMY_PRJNAME})
  set_target_properties(${META_GAPI_DUMMY_LIBNAME} PROPERTIES PREFIX "")
  set_target_properties(${META_GAPI_DUMMY_LIBNAME} PROPERTIES SUFFIX ".a.${META_GAPI_DUMMY_VERSION}")
endif ()

custom_enable_cxx17(${META_GAPI_DUMMY_LIBNAME})

target_link_libraries(${META_GAPI_DUMMY_LIBNAME} libmodule_core)

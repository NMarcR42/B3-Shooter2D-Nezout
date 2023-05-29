cmake_minimum_required(VERSION 3.8)

project("Shooter2D")

set(CMAKE_CXX_STANDARD 20)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.env)
  file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/.env ENV_VARS)
  foreach(env_var ${ENV_VARS})
    string(REGEX REPLACE "^[^=]+=" "" env_value ${env_var})
    string(REGEX REPLACE "=.*$" "" env_name ${env_var})
    set(ENV{${env_name}} ${env_value})
  endforeach()
endif()

if(DEFINED ENV{PATH_VCPKG})
	include($ENV{PATH_VCPKG})
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)

set (HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set (SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set (HEADERS
    ${HEADER_DIR}/Bullet.h
    ${HEADER_DIR}/Enemy.h
    ${HEADER_DIR}/EnemyAnimation.h
    ${HEADER_DIR}/Player.h
    ${HEADER_DIR}/PlayerAnimation.h

)

set (SOURCES
    ${SOURCE_DIR}/Bullet.cpp
    ${SOURCE_DIR}/Enemy.cpp
    ${SOURCE_DIR}/EnemyAnimation.cpp
    ${SOURCE_DIR}/Player.cpp
    ${SOURCE_DIR}/PlayerAnimation.cpp
    ${SOURCE_DIR}/Shooter2D.cpp
)

#find_package(sfml REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Shooter2D PROPERTY CXX_STANDARD 20)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)

#target_link_libraries(${PROJECT_NAME}
#  PRIVATE
#    sfml::sfml)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${HEADER_DIR}>
  PRIVATE
    ${SOURCE_DIR}
)


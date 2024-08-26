cmake_minimum_required(VERSION 3.0.0)
project(wxSqlquery VERSION 0.1.0)


if (DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG}})
endif()

find_package(wxWidgets REQUIRED COMPONENTS net core base adv)



include(${wxWidgets_USE_FILE})


file(GLOB project_GLOB
    src/*.cpp
)

add_executable(${PROJECT_NAME} ${project_GLOB})


target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS})


target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib/wxsqlite3.o)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib/sqlite3mc_amalgamation.o)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

#message( "--Root--" ${wxWidgets_ROOT_DIR} )
#message( "--Lib dir--" ${wxWidgets_LIB_DIR} )
message( "--Lib dir    --" ${wxWidgets_LIBRARIES} )
message( "--include dir--" ${wxWidgets_INCLUDE_DIRS} )

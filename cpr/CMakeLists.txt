#this is the CMakeLists.txt that should be put under `<your_project_dir>/src/cpr`
aux_source_directory(. CPR_SRCS)

add_library(cpr SHARED ${CPR_SRCS} )
target_link_libraries(cpr curl)

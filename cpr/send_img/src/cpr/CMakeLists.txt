aux_source_directory(. CPR_SRCS)

add_library(cpr SHARED ${CPR_SRCS} )
target_link_libraries(cpr curl)

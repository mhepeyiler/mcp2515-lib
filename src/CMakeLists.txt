add_library(mcp2515 
            mcp2515.c)

target_include_directories(mcp2515
                            PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}/include")
    

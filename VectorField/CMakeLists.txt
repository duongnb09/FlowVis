project(VectorField)
file(GLOB UTL_HEADERS *.h)
file(GLOB UTL_SOURCES *.cpp)
add_library(VectorField ${UTL_SOURCES} ${UTL_HEADERS})

include_directories(${Utilities_SOURCE_DIR})
target_link_libraries(VectorField Utilities)

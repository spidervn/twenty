
cmake_minimum_required(VERSION 2.6)
project (MemoryAccurate)

# The version number
set(MemoryAccurate_VERSION_MAJOR 1)
set(MemoryAccurate_VERSION_MINOR 0)

option (USE_MYMATH 
        "Use tutorial provided math implementation" ON) 

configure_file (
	"${PROJECT_SOURCE_DIR}/memaccu.h.in"
	"${PROJECT_BINARY_DIR}/memaccu.h"
)

if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# include_directories("${PROJECT_BINARY_DIR}")
# include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
# add_subdirectory (MathFunctions)

add_library(MathFunctions mysqrt.cxx)
add_executable(MemoryAccurate memaccu.cpp)
target_link_libraries(MemoryAccurate ${EXTRA_LIBS})

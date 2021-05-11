# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\helloWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\helloWidget_autogen.dir\\ParseCache.txt"
  "helloWidget_autogen"
  )
endif()

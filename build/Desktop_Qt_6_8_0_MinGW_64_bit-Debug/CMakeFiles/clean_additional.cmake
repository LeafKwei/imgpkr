# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\imgpkr_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\imgpkr_autogen.dir\\ParseCache.txt"
  "imgpkr_autogen"
  )
endif()

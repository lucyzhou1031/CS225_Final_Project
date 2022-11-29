# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225_Final_Project/final_project/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225_Final_Project/final_project/lib/cs225/HSLAPixel.cpp"
  "/workspaces/cs225/CS225_Final_Project/final_project/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225_Final_Project/final_project/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225_Final_Project/final_project/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225_Final_Project/final_project/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225_Final_Project/final_project/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225_Final_Project/final_project/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/cs225/CS225_Final_Project/final_project/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225_Final_Project/final_project/build/CMakeFiles/cmake.verify_globs")
endif()

# nim_graph_sources at lib/CMakeLists.txt:19 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225_Final_Project/final_project/lib/nim_graph/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225_Final_Project/final_project/lib/nim_graph/graph.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225_Final_Project/final_project/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225_Final_Project/final_project/src/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225_Final_Project/final_project/src/Graph.cpp"
  "/workspaces/cs225/CS225_Final_Project/final_project/src/data.cpp"
  "/workspaces/cs225/CS225_Final_Project/final_project/src/dfs.cpp"
  "/workspaces/cs225/CS225_Final_Project/final_project/src/pageRank.cpp"
  "/workspaces/cs225/CS225_Final_Project/final_project/src/utils.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225_Final_Project/final_project/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:131 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS225_Final_Project/final_project/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS225_Final_Project/final_project/tests/test.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS225_Final_Project/final_project/build/CMakeFiles/cmake.verify_globs")
endif()

macro(run_conan)
# Download automatically, you can also just copy the conan.cmake file
#if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(
    STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
       "${CMAKE_BINARY_DIR}/conan.cmake")
#endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
  REQUIRES
  ${CONAN_EXTRA_REQUIRES}
  catch2/2.11.3
  docopt.cpp/0.6.2
  spdlog/1.5.0
  boost/1.72.0
  folly/2019.10.21.00
  OPTIONS
  ${CONAN_EXTRA_OPTIONS}
  BASIC_SETUP
  CMAKE_TARGETS # individual targets to link to
  IMPORTS
  ${CONAN_IMPORTS}
  BUILD
  missing)
endmacro()

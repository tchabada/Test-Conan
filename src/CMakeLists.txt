add_executable(main "main.cpp" "boost_await.h")

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    if(WIN32)
        target_compile_options(main
        PUBLIC
            /std:c++latest
            -fms-compatibility -Xclang -fcoroutines-ts
        )

        target_compile_definitions(main
        PUBLIC
            USE_PORTABLE_COROUTINE_HANDLE
            _RESUMABLE_FUNCTIONS_SUPPORTED  # _EXPERIMENTAL_RESUMABLE_
        )

    elseif(UNIX OR APPLE)
        target_compile_options(main
        PUBLIC
            -std=c++2a -stdlib=libc++
            -fcoroutines-ts
        )
    endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_compile_options(main
    PUBLIC
        -std=gnu++2a
        -fcoroutines -fconcepts # -fno-exceptions
    )

elseif(MSVC)
    target_compile_options(main
    PUBLIC
        /std:c++latest /await
    )

endif()

target_link_libraries(
  main PRIVATE project_options project_warnings CONAN_PKG::folly CONAN_PKG::boost CONAN_PKG::docopt.cpp
                CONAN_PKG::fmt CONAN_PKG::spdlog)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.16.0 # Last version supporting C++14
)
# Avoid overriding the parent project's compiler settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(persian_date_tests persian_date_tests.cpp)
target_link_libraries(persian_date_tests PRIVATE PersianDate_Cpp GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(persian_date_tests)
cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-DUNIT_TEST)
set(CMAKE_EXPORT_COMPILE_COMMANDS)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v3.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# --- Fetch GTEST ------------------------------------------------------------------
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# ------------------------------------------------------------------------------


project(ftxui-starter
  LANGUAGES CXX
  VERSION 1.0.0
)

# --- Create executable --------------------------------------------------------

# This is a bit of a hack, but we can clean it up later
# Get all .cpp files, set SRC_FILES variable
file(GLOB_RECURSE SRC_FILES
  src/UI.cpp
  src/uuid.cpp
  src/logger.cpp
  #===== Add new folders here!=====#
  src/Country/*.cpp
  src/Country/BattleStrategy/*.cpp

  src/Factories/*.cpp
  src/Military/*.cpp
  src/UI.cpp
  src/uuid.cpp
  src/logger.cpp

  src/Entities/*.cpp
  src/Entities/Troop/*.cpp
  src/Entities/Vehicle/*.cpp
  src/Entities/Vehicle/AirVehicle/*.cpp
  src/Entities/Vehicle/GroundVehicle/*.cpp
  src/Entities/Vehicle/WaterVehicle/*.cpp
  src/Entities/WeaponTemplateMethod/*.cpp

  src/MapRegions/*.cpp

  # src/Military/*.cpp

  src/War/*.cpp
  src/War/WarPhases/*.cpp
  src/War/Battle/*.cpp
)

# Create the `ftxui-starter` executable in build/, add all .cpp files
add_executable(${PROJECT_NAME}
    src/main.cpp
    ${SRC_FILES}
    )

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME}
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)

enable_testing()
add_executable(
    Entity_Military_UnitTests
    src/Entity_Military_UnitTests.cpp
    ${SRC_FILES}
)
target_include_directories(Entity_Military_UnitTests PUBLIC src)
target_link_libraries(Entity_Military_UnitTests
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  GTest::gtest_main
)

add_executable(
    Map_UnitTest
    src/Map_UnitTest.cpp
    ${SRC_FILES}
)
target_include_directories(Map_UnitTest PUBLIC src)
target_link_libraries(Map_UnitTest
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  GTest::gtest_main
)

add_executable(
    Country_UnitTest
    src/Country_UnitTest.cpp
    ${SRC_FILES}
)
target_include_directories(Country_UnitTest PUBLIC src)
target_link_libraries(Country_UnitTest
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  GTest::gtest_main
)

# ------------------------------------------------------------------------------
# ------------TESTING-----------------------------------------------------------
enable_testing()
add_executable(
  WarPhase_UnitTest
  src/WarPhase_UnitTest.cpp
  ${SRC_FILES}
)
target_include_directories(WarPhase_UnitTest PUBLIC src)
target_link_libraries(WarPhase_UnitTest
  PRIVATE ftxui::screen PRIVATE ftxui::dom PRIVATE ftxui::component
  GTest::gtest_main
)
add_executable(
    Factory_UnitTest
    src/Factory_UnitTest.cpp
  ${SRC_FILES}
)
target_include_directories(Factory_UnitTest PUBLIC src)
target_link_libraries(Factory_UnitTest
  PRIVATE ftxui::screen PRIVATE ftxui::dom PRIVATE ftxui::component
  GTest::gtest_main
)
# --- Emscripten build (can ignore) --------------------------------------------
if (EMSCRIPTEN)
  string(APPEND CMAKE_CXX_FLAGS " -s USE_PTHREADS")
  string(APPEND CMAKE_EXE_LINKER_FLAGS " -s ASYNCIFY")
  string(APPEND CMAKE_EXE_LINKER_FLAGS " -s PROXY_TO_PTHREAD")

  foreach(file "index.html" "run_webassembly.py")
    configure_file("src/${file}" ${file})
  endforeach(file)
endif()
# ------------------------------------------------------------------------------
include(GoogleTest)
gtest_discover_tests(Entity_Military_UnitTests Map_UnitTest)

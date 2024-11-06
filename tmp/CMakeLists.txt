
cmake_minimum_required(VERSION 2.8.12)

project("generated_code")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)


message(STATUS "Configuring AMM_Standard...")
add_library(AMM_Standard_lib AMM_Standard.cxx)
target_link_libraries(AMM_Standard_lib fastcdr fastrtps)

add_executable(AMM_Standard AMM_StandardPubSubTypes.cxx AMM_StandardPublisher.cxx AMM_StandardSubscriber.cxx AMM_StandardPubSubMain.cxx)
target_link_libraries(AMM_Standard fastcdr fastrtps
        AMM_Standard_lib )




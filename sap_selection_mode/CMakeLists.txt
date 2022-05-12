################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 3.0.2)
project(sap_selection_mode)


SET(CMAKE_CXX_FLAGS "-std=c++0x")
add_compile_options(-std=c++0x)

################################################################################
# Find catkin packages and libraries for catkin and system dependencies
################################################################################

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#새로 추가
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  actionlib
  actionlib_msgs
  nav_msgs
  message_generation
  move_base_msgs
)

find_package(MySqlClient REQUIRED)

################################################################################
# Setup for python modules and scripts
################################################################################

################################################################################
# Declare ROS messages, services and actions
################################################################################
#add_action_files(
#  DIRECTORY action
#)

#add_message_files(FILES 파일명.msg)
add_message_files(
  FILES 
    Msg.msg 
    mode_msg.msg
)

generate_messages(
  DEPENDENCIES
    std_msgs
    actionlib_msgs
    move_base_msgs
)
################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################
catkin_package(
  CATKIN_DEPENDS 
    roscpp
    std_msgs
    actionlib
    actionlib_msgs
    nav_msgs
    move_base_msgs
)

################################################################################
# Build
################################################################################
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${MYSQL_INCLUDE_DIRS}
)

##test_navigation 노드에 대한 빌드 옵션
#add_executable(mode3_node src/mode_three.cpp)

#target_link_libraries(
#  mode3_node
#  ${catkin_LIBRARIES}
#)

#add_dependencies(
#  mode2_node 
#  ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
#)

#set_target_properties(mode2_node PROPERTIES LINKER_LANGUAGE CXX)
##실험 노드에 대한 빌드 옵션
add_executable(selection_node src/selection_mode.cpp)

target_link_libraries(
   selection_node
   ${catkin_LIBRARIES}
   ${MYSQL_LIBRARIES}
)

add_dependencies(
  selection_node
  ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
)



################################################################################
# Install
################################################################################
install(DIRECTORY launch maps param rviz
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


################################################################################
# Test
################################################################################

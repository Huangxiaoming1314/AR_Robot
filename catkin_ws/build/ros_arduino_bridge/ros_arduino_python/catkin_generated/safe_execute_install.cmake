execute_process(COMMAND "/home/hxm/catkin_ws/build/ros_arduino_bridge/ros_arduino_python/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/hxm/catkin_ws/build/ros_arduino_bridge/ros_arduino_python/catkin_generated/python_distutils_install.sh) returned error code ")
endif()

execute_process(COMMAND "/home/hxm/catkin_ws/build/nav/autolabor_pro1-master/autolabor_pro1_nav/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/hxm/catkin_ws/build/nav/autolabor_pro1-master/autolabor_pro1_nav/catkin_generated/python_distutils_install.sh) returned error code ")
endif()

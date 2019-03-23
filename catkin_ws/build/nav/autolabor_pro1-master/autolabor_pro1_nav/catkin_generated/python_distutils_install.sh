#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/hxm/catkin_ws/src/nav/autolabor_pro1-master/autolabor_pro1_nav"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/hxm/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/hxm/catkin_ws/install/lib/python2.7/dist-packages:/home/hxm/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/hxm/catkin_ws/build" \
    "/usr/bin/python" \
    "/home/hxm/catkin_ws/src/nav/autolabor_pro1-master/autolabor_pro1_nav/setup.py" \
    build --build-base "/home/hxm/catkin_ws/build/nav/autolabor_pro1-master/autolabor_pro1_nav" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/hxm/catkin_ws/install" --install-scripts="/home/hxm/catkin_ws/install/bin"
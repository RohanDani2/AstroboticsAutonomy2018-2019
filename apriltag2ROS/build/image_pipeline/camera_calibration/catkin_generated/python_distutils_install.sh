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

echo_and_run cd "/home/rohan/apriltag2ROS/src/image_pipeline/camera_calibration"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/rohan/apriltag2ROS/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/rohan/apriltag2ROS/install/lib/python2.7/dist-packages:/home/rohan/apriltag2ROS/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/rohan/apriltag2ROS/build" \
    "/usr/bin/python" \
    "/home/rohan/apriltag2ROS/src/image_pipeline/camera_calibration/setup.py" \
    build --build-base "/home/rohan/apriltag2ROS/build/image_pipeline/camera_calibration" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/rohan/apriltag2ROS/install" --install-scripts="/home/rohan/apriltag2ROS/install/bin"

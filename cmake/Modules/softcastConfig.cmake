INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SOFTCAST softcast)

FIND_PATH(
    SOFTCAST_INCLUDE_DIRS
    NAMES softcast/api.h
    HINTS $ENV{SOFTCAST_DIR}/include
        ${PC_SOFTCAST_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SOFTCAST_LIBRARIES
    NAMES gnuradio-softcast
    HINTS $ENV{SOFTCAST_DIR}/lib
        ${PC_SOFTCAST_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/softcastTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SOFTCAST DEFAULT_MSG SOFTCAST_LIBRARIES SOFTCAST_INCLUDE_DIRS)
MARK_AS_ADVANCED(SOFTCAST_LIBRARIES SOFTCAST_INCLUDE_DIRS)

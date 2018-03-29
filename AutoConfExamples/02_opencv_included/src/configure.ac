AC_INIT(LenaRead, [0.1])
AC_PREREQ(2.5)

AM_INIT_AUTOMAKE(1.1)
AC_CONFIG_MACRO_DIR(m4)

AC_PROG_CXX

PKG_CHECK_MODULES(OPENCV, [opencv], [], [AC_MSG_ERROR("OpenCV not found")])


AC_OUTPUT(Makefile main/Makefile)


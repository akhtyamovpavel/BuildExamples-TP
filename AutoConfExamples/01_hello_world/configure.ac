# Init autoconf project
AC_INIT([Hello], [0.1])

AC_CONFIG_AUX_DIR([build])  # Build folder
# Init automake with compile flags
AM_INIT_AUTOMAKE([-Wall -Werror foreign])


# Check for C++ compiler
AC_PROG_CXX

# Configure header files
AC_CONFIG_HEADERS([config.h])

# Tell automake to create makefiles
AC_CONFIG_FILES([
 Makefile
  src/Makefile
  ])

# Generate the output
AC_OUTPUT

bin_PROGRAMS = myopencv

SRCDIR = $(abs_top_srcdir)
myopencv_SOURCES = main.cpp
myopencv_CPPFLAGS = -I$(SRCDIR) -I$(SRCDIR)/include $(OPENCV_CFLAGS)
myopencv_LDFLAGS = $(LDFLAGS)
myopencv_LDADD = $(OPENCV_LIBS)

AUTOMAKE_OPTIONS = foreign

#include_HEADERS = ev.h ev++.h event.h

#lib_LIBRARIES = libev.a

lib_LIBRARIES = libev.a
libev_a_CFLAGS = -g -Wall
#libev_a_SOURCES = ev.c event.c ev_epoll.c ev_kqueue.c ev_poll.c ev_port.c \
#		ev_select.c ev_win32.c
libev_a_SOURCES = ev.c event.c

libev_a_LDFLAGS =
libev_a_INCLUDE = ev.h ev++.h event.h ev_wrap.h ev_vars.h 

libevlibdir = $(top_srcdir)/lib

libevincludedir = $(top_srcdir)/include
libevinclude_HEADERS = ev.h ev++.h event.h

AUTOMAKE_OPTIONS=foreign

SUBDIRS=libev

bin_PROGRAMS=gdb_libev

gdb_libev_SOURCES=ev_signal.c

gdb_libev_CFLAGS=-I${top_srcdir}/include -g

gdb_libev_LDADD=${top_srcdir}/lib/libev.a

gdb_libevdir=${top_srcdir}/bin

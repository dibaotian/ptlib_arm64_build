ifndef PTLIBDIR
PTLIBDIR := $(HOME)/ptlib
endif

include $(PTLIBDIR)/make/unix.mak

OBJDIR	= $(PT_OBJDIR)
LIBDIR  = $(PT_LIBDIR)
TARGET  = $(LIBDIR)/$(PTLIB_FILE)
VERSION_FILE = $(PTLIBDIR)/version.h

##########################################
PLUGIN_DIR		= ../plugins

PLATFORM_SRC_DIR        = ./

VPATH_CXX		:= $(PLATFORM_SRC_DIR)

GETDATE_SOURCE = $(PLATFORM_SRC_DIR)/getdate.tab.c

SOURCES	+= \
	$(PLATFORM_SRC_DIR)/socket.cxx \
	$(PLATFORM_SRC_DIR)/udll.cxx \
	$(PLATFORM_SRC_DIR)/channel.cxx \
	$(PLATFORM_SRC_DIR)/osutil.cxx \
	$(PLATFORM_SRC_DIR)/tlib.cxx \
	$(PLATFORM_SRC_DIR)/config.cxx \
	$(PLATFORM_SRC_DIR)/switch.cxx \
	$(GETDATE_SOURCE)\
	$(PLATFORM_SRC_DIR)/threadpool.cxx \
	$(PLATFORM_SRC_DIR)/ipacl.cxx \
	$(PLATFORM_SRC_DIR)/qchannel.cxx \
	$(PLATFORM_SRC_DIR)/delaychan.cxx \
	$(PLATFORM_SRC_DIR)/memfile.cxx \
	$(PLATFORM_SRC_DIR)/random.cxx \
	$(PLATFORM_SRC_DIR)/inetprot.cxx \
	$(PLATFORM_SRC_DIR)/notifier_ext.cxx \
	$(PLATFORM_SRC_DIR)/assert.cxx \
	$(PLATFORM_SRC_DIR)/pluginmgr.cxx \
	$(PLATFORM_SRC_DIR)/sockets.cxx \
	$(PLATFORM_SRC_DIR)/psockbun.cxx \
	$(PLATFORM_SRC_DIR)/qos.cxx \
	$(PLATFORM_SRC_DIR)/ptime.cxx \
	$(PLATFORM_SRC_DIR)/osutils.cxx \
	$(PLATFORM_SRC_DIR)/safecoll.cxx \
	$(PLATFORM_SRC_DIR)/collect.cxx \
	$(PLATFORM_SRC_DIR)/contain.cxx \
	$(PLATFORM_SRC_DIR)/object.cxx   # must be last module

#######################################################

include ../make/common.mak

#######################################################

alllibs:
	$(MAKE) both
	$(MAKE) bothshared

ifdef REQUIRES_SEPARATE_SWITCH 
$(OBJDIR)/switch.o: $(PLATFORM_SRC_DIR)/switch.cxx
	@if [ ! -d $(OBJDIR) ] ; then mkdir -p $(OBJDIR) ; fi
	$(Q_CC)$(CXX) $(STDCCFLAGS) $(CFLAGS) -c $< -o $@
endif

$(OBJDIR)/getdate.tab.o: $(GETDATE_SOURCE)
	$(Q_CC)$(CC) $(STDCCFLAGS) $(CFLAGS) -c $< -o $@

#######################################################

LIB_BASENAME=$(PTLIB_BASE)
LIB_FILENAME=$(PTLIB_FILE)

include $(PTLIBDIR)/make/lib.mak

#######################################################

# End of Makefile

#!/usr/bin/make -f

PLUGIN = dark-theme
PLUGIN_CFLAGS = -DLOCALEDIR='"$(datadir)/locale"' \
                -DPLUGIN_DATADIR='"$(pkgdatadir)"' \
                -DGETTEXT_PACKAGE='"$(PLUGIN)"'

VPATH ?= .

# fetch from https://github.com/b4n/geany-plugin.mk
include $(VPATH)/geany-plugin.mk/geany-plugin.mk

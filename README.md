# Dark UI Theme plugin

This Geany plugin requests a dark theme variant to be used for Geany's UI.
It requires the use of a GTK3 Geany build, and a GTK3 theme that has a dark
variant (like the default Adwaita theme and other popular themes).

## Compilation

Fetch geany-plugin.mk from https://github.com/b4n/geany-plugin.mk inside the
plugin's source directory:

    $ git submodule update --init

And then run `make` and `make install` (that last one possibly as root).

## Usage

Enable the plugin in Geany's Plugin Manager (*Tools -> Plugin Manager*, and
select the *Dark UI Theme* plugin).

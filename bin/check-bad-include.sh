#!/bin/sh

# find files that incorrectly include top level files

grep -RiP '.. include:: .*/[^_\/]+[^\/]*\.rst' source/

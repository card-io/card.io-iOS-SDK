#!/bin/sh

# Set Git to ignore locally changed Constants.h after the default is set

case "$1" in
  ignore)
    git update-index --assume-unchanged ScanExample/Constants.h
  ;;
  unignore)
    git update-index --no-assume-unchanged ScanExample/Constants.h
  ;;
  *)
    echo "Usage: `basename $0` { ignore | unignore }"
  ;;
esac


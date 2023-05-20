#! /bin/sh

if [ -z "${1^^}" ] || [ "${1^^}" = "DEFAULT" ]; then
  echo "Setting default MODE = INCLUDE and BUILD = DEBUG parameters [MODE { LIBRARY, INCLUDE }, BUILD { DEBUG, RELEASE }]"
  DEFAULT_MODE="INCLUDE"
  DEFAULT_BUILD="DEBUG"
else
  if [ -z "$1" ]; then
    echo "Pass MODE { LIBRARY, INCLUDE }"
    return 1
  elif ([ "${1^^}" != "LIBRARY" ] && [ "${1^^}" != "INCLUDE" ]); then
      echo "Pass BUILD { LIBRARY, INCLUDE } current value '${1^^}' is wrong!"
      return 1
    fi
  if [ -z "$2" ]; then
    echo "Pass BUILD { DEBUG, RELEASE }"
    return 1
  elif ([ "${2^^}" != "DEBUG" ] && [ "${2^^}" != "RELEASE" ]); then
    echo "Pass BUILD { DEBUG, RELEASE } current value '${2^^}' is wrong!"
    return 1
  fi
  DEFAULT_MODE="${1^^}"
  DEFAULT_BUILD="${2^^}"
fi

MODE=$DEFAULT_MODE
BUILD=$DEFAULT_BUILD

return 0;
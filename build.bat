@echo off
setlocal enabledelayedexpansion

set OUT=game.gb
set FLAGS=-Wa-l -Wl-m -Iinclude -Isrc

set SRC=
for /r src %%f in (*.c) do (
  set SRC=!SRC! "%%f"
)

lcc %FLAGS% -o %OUT% %SRC%

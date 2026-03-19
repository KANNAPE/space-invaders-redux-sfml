@ECHO OFF
pushd %~dp0\
call premake5 vs2022 --file=./SpaceInvadersRedux.lua
popd
PAUSE
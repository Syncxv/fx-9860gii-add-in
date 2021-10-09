@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.


if exist TEST.G1A  del TEST.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"D:\CASIO SDK\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"D:\CASIO SDK\Tools\MakeAddinHeader363.exe" "C:\Users\USER\Documents\CASIO\fx-9860G SDK\test"
if not exist TEST.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end


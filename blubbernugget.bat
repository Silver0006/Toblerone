@echo off
tasklist /FI "IMAGENAME eq Toblerone.exe" /FO CSV > search.log

FOR /F %%A IN (search.log) DO IF %%~zA EQU 0 GOTO end

start Toblerone.exe

:end

del search.log
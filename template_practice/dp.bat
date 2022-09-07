@echo off  
:loop  
    rand.exe>data.txt  
    luogu1114.exe<data.txt>luogu1114.out  
    std.exe<data.txt>std.out  
    fc luogu1114.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
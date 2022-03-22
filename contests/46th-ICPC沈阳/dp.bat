@echo off  
:loop  
    rand.exe>data.txt  
    _B.exe<data.txt>_B.out  
    std.exe<data.txt>std.out  
    fc _B.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
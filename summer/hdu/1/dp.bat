@echo off  
:loop  
    rand.exe>data.txt  
    b.exe<data.txt>b.out  
    std.exe<data.txt>std.out  
    fc b.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
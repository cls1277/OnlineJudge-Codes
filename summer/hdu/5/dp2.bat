@echo off  
:loop  
    rand2.exe>data.txt  
    J.exe<data.txt>J.out  
    Jstd.exe<data.txt>Jstd.out  
    fc J.out Jstd.out  
if not errorlevel 1 goto loop  
pause  
goto loop
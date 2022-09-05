@echo off  
:loop  
    rand.exe>data.txt  
    gaojingchu1.exe<data.txt>gaojingchu1.out  
    python std.py<data.txt>std.out  
    fc gaojingchu1.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
@echo off  
:loop  
    rand.exe>data.txt  
    F.exe<data.txt>F.out  
    Fstd.exe<data.txt>Fstd.out  
    fc F.out Fstd.out  
if not errorlevel 1 goto loop  
pause  
goto loop
@echo off  
:loop  
    rand.exe>data.txt  
    af.exe<data.txt>af.out  
    Edd.exe<data.txt>Edd.out  
    fc af.out Edd.out  
if not errorlevel 1 goto loop  
pause
goto loop
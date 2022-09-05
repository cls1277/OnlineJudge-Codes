@echo off  
:loop  
    rand.exe > data.txt
    C__.exe < data.txt > C_.txt
    dp.exe < C_.txt > dp.txt
    fc dp.txt Cstd.txt
if not errorlevel 1 goto loop  
pause  
goto loop
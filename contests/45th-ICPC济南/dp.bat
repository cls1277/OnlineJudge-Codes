@echo off  
:loop  
    rand.exe > data.txt  
    G.exe < data.txt > Gstd.out
    Gg.exe < Gstd.out > Gg.out
    fc Gg.out output.out  
if not errorlevel 1 goto loop  
pause  
goto loop
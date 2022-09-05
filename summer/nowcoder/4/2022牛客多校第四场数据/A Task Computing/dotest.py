import os

for i in range(10):
    if i < 10:
        filestr = '0' + str(i)
    else:
        filestr = str(i)

    if os.path.exists(filestr):
        os.rename(filestr, str(i) + '.in')
        print('Renamed ' + str(i) + ' to ' + str(i) + '.in')
    
    if i < 10:
        filestr = '0' + str(i) + 'a'
    else:
        filestr = str(i) + 'a'
    
    if os.path.exists(filestr):
        os.rename(filestr, str(i) + '.out')
        print('Renamed ' + str(i) + ' to ' + str(i) + '.out')
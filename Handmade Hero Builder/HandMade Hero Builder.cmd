@ECHO OFF
COLOR 4e
set PLAT=Visual Studio 2015
Setlocal EnableDelayedExpansion
Set _RNDLength=10
Set _Alphanumeric=ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789
Set _Str=%_Alphanumeric%987654321
:_LenLoop
IF NOT "%_Str:~18%"=="" SET _Str=%_Str:~9%& SET /A _Len+=9& GOTO :_LenLoop
SET _tmp=%_Str:~9,1%
SET /A _Len=_Len+_tmp
Set _count=0
SET _RndAlphaNum=
:_loop
Set /a _count+=1
SET _RND=%Random%
Set /A _RND=_RND%%%_Len%
SET _RndAlphaNum=!_RndAlphaNum!!_Alphanumeric:~%_RND%,1!
If !_count! lss %_RNDLength% goto _loop
set ENC=!_RndAlphaNum!
@ECHO OFF
:MENU
CLS
:::  _  _                 _  __  __           _       _  _                
::: | || | __ _  _ _   __| ||  \/  | __ _  __| | ___ | || | ___  _ _  ___ 
::: | __ |/ _` || ' \ / _` || |\/| |/ _` |/ _` |/ -_)| __ |/ -_)| '_|/ _ \
::: |_||_|\__,_||_||_|\__,_||_| _|_|\__,_|\__,_|\___||_||_|\___||_|  \___/
:::   /_\  _  _ | |_  ___  ___ | _ ) _  _ (_)| | __| | ___  _ _           
:::  / _ \| || ||  _|/ _ \|___|| _ \| || || || |/ _` |/ -_)| '_|          
::: /_/ \_\\_,_| \__|\___/     |___/ \_,_||_||_|\__,_|\___||_|            
:::                                                                       
for /f "delims=: tokens=*" %%A in ('findstr /b ::: "%~f0"') do @echo(%%A
ECHO.
ECHO         1)  Visual Studio 2015
ECHO         2)  Linux GNU Compiler
ECHO         3)  Linux Winelib
ECHO         4)  OS X port
ECHO         5)  Swift Cocoa Platform
ECHO         6)  X protocol C-language binding platform
ECHO         7)  Android NDK platform
ECHO         8)  iOS port
ECHO         9)  Qt platform
ECHO         0)  Quit Without Building
ECHO.

:MENUOPTION
SET /P USERINPUT=Enter Option==^>
IF '%USERINPUT%'=='' GOTO :ERROR
IF %USERINPUT%==1 GOTO :VS2015
IF %USERINPUT%==2 GOTO :GNU
IF %USERINPUT%==3 GOTO :WINELIB
IF %USERINPUT%==4 GOTO :OSX
IF %USERINPUT%==5 GOTO :SWIFT
IF %USERINPUT%==6 GOTO :XCB
IF %USERINPUT%==7 GOTO :NDK
IF %USERINPUT%==8 GOTO :IOS
IF %USERINPUT%==9 GOTO :QT
IF %USERINPUT%==0 GOTO :QUIT
IF %USERINPUT%==x GOTO :QUIT
IF %USERINPUT%==X GOTO :QUIT
GOTO INVALID

:VS2015
"bin/php.exe" -q platforms/vs2015.php 
pause

GOTO MENU

:GNU
"bin/php.exe" -q platforms/gpp.php 
pause

GOTO QUIT

:WINELIB
"bin/php.exe" -q platforms/winelib.php 
pause

GOTO QUIT

:OSX
"bin/php.exe" -q platforms/osx.php 
pause

GOTO QUIT

:SWIFT
"bin/php.exe" -q platforms/swift.php 
pause

GOTO QUIT

:XCB
"bin/php.exe" -q platforms/xcb.php 
pause

GOTO QUIT

:NDK
"php/php.exe" -q platforms/ndk.php 
pause

GOTO QUIT

:ERROR
ECHO.
ECHO ERROR: Please select an option (1,2,3,4,5,6,7,8,9,0) and press enter
ECHO.
GOTO MENUOPTION

:INVALID
ECHO.
ECHO ERROR: "%USERINPUT%" is not an existing option
ECHO.
GOTO MENUOPTION
:BUILD

color 1e
cd make
cls 
"..\bin\php\php.exe" -q make.php -b "full" %SIGN%
cd ..
pause
:QUIT
pause
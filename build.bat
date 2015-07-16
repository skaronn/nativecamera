@echo off
call lime rebuild . flash -debug %*
call lime rebuild . flash %*
::call lime rebuild . windows -debug %*
::call lime rebuild . windows %*
::call lime rebuild . android -debug %*
::call lime rebuild . android %*
::call lime rebuild . iphone -debug %*
::call lime rebuild . iphone %*
pause
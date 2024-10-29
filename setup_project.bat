@echo off
break>"%cd%\vec3.h"
break>"%cd%\vec4.h"
break>"%cd%\mat4.h"
cmake -S %cd% -B %cd%/build
pause
OpenGLDirectStateAccessEmulation
================================

A very simple and flat direct state access emulation layer


Configuration
-------------
To configure see ogl\_dsa\_config.h

Requirements
------------
The emulation layer trys to inject it self (if needed) in all relevant bind functions, like glBindTexture. So it is required that those are function pointers (on windows glBindTexture is exposed via gl.h as a function prototype so you will get an error there).


Tested on VC 2014 CPT on x64 with customize ogl\_dsa\_config.h

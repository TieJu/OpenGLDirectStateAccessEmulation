OpenGLDirectStateAccessEmulation
================================

A very simple and flat direct state access emulation layer


Configuration
-------------
To configure see ogl\_dsa\_config.h

Requirements
------------
The emulation layer trys to inject it self (if needed) in all relevant bind functions, like glBindTexture. So it is required that those are function pointers (on windows glBindTexture is exposed via gl.h as a function prototype so you will get an error there).

Limitations
-----------
The emulation layer uses thread local storage to track current bound objects, so you can't switch OpenGL contexts to other threads or it will break tracking.

Why is the interface a mixture of ARB and EXT direct state access?
------------------------------------------------------------------
Because the texture object part of the ARB extension no longer takes texture target arguments, they are set with glCreateTextures. This would require to track the texture object target, which requires a shared data structure shared between all threads, which leads to access tracking (via mutex) of this data structure.
So the easy way was to use the EXT variant for this to avoid this issue and wrap the ARB variant if needed.

Tested On
---------
VC 2014 CPT on x64 with customize ogl\_dsa\_config.h

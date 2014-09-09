#pragma once
/**
 *
 **/

#define PLATFORM_HEADER             <Windows.h>
#define OPENGL_HEADER               <gl/gl.h>
#define OPENGL_EXT_HEADER           "glext.h"
#define OPENGL_PLATFORM_EXT_HEADER  "wglext.h"

#define RemapGLName(name_)          name_

#define GetProcAddress(name_)       SDL_GL_GetProcAddress(name_)

#if defined(COMPILER_KNOWNS_DECLTYPE)
#define CheckedFunctionLoad(name_)  ( ( RemapGLName(name_) = reinterpret_cast<decltype( RemapGLName(name_) )>>( GPA(#name_) ) ) != nullptr )
#else
#define CheckedFunctionLoad(name_)  ( avoid_typecheck( & RemapGLName(name_) , GPA(#name_) ) != nullptr )
#endif


//#define GL_DSA_SUPRESS_64BIT_WARNINGS

#define PLATFORM_WINDOWS
#define PLATFORM_OSX
#define PLATFORM_LINUX
#define DEFINE_INTERFACE_POINTERS
#define INCLUDE_PLATFORM_HEADER
#define INCLUDE_EXT_HEADER
#define INCLUDE_FPLATFORM_EXT_HEADER
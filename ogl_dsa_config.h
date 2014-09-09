#pragma once
/**
 *
 **/

/**
 * Include file for platform specific header.
 * Only required if OGL_DSA_INCLUDE_PLATFORM_HEADER is defined.
 */
#define OGL_DSA_PLATFORM_HEADER             <Windows.h>
/**
 * Include file of open gl header.
 */
#define OGL_DSA_OPENGL_HEADER               <gl/gl.h>
/**
 * Include file for open gl extension specific header.
 * Only required if OGL_DSA_INCLUDE_EXT_HEADER is defined.
 */
#define OGL_DSA_OPENGL_EXT_HEADER           "glext.h"
/**
 * Include file for platform specific open gl extension header.
 * Only required if OGL_DSA_INCLUDE_FPLATFORM_EXT_HEADER is defined.
 */
#define OGL_DSA_OPENGL_PLATFORM_EXT_HEADER  "wglext.h"
/**
 * With this macro public open gl entry point names are mapped to
 * your function pointer names.
 * As an example, usually on my projects, i put a 't' in front of
 * each function pointer name.
 * Default is name_
 */
#define RemapGLName(name_)          name_
/**
 * This defines the function that should be called to get a
 * function pointer from open gl.
 * Default id SDL_GL_GetProcAddress(name_)
 */
#define GetProcAddress(name_)       SDL_GL_GetProcAddress(name_)

#if 1
/**
 * This handles the loading of the entry points and checking
 * them for NULL.
 * This variant uses decltype to cast the return value of 
 * GetProcAddress to match the pointer type.
 */
#define CheckedFunctionLoad(name_)  ( ( RemapGLName(name_) = reinterpret_cast<decltype( RemapGLName(name_) )>>( GetProcAddress(#name_) ) ) != nullptr )
#else
/**
 * This handles the loading of the entry points and checking
 * them for NULL.
 * This variant casts the target pointer to void* to avoid
 * type-checking. Only use this if your compile can't handle
 * decltype.
 */
#define CheckedFunctionLoad(name_)  ( *reinterpret_cast<void**>( &RemapGLName(name_) ) = GetProcAddress(#name_) ) != nullptr )
#endif

/**
 * Uncomment this on x64 to disable some warnings.
 */
//#define GL_DSA_SUPRESS_64BIT_WARNINGS

#if defined(_WIN_32) || defined(__WIN32__) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#define OGL_DSA_PLATFORM_WINDOWS
#else
#error "Unsupported system!"
#endif
//#define OGL_DSA_PLATFORM_OSX
//#define OGL_DSA_PLATFORM_LINUX
/**
 * If this is defined, ogl_dsa.cpp contains
 * definition of all interface pointers
 * provided by ogl_dsa.h.
 */
#define OGL_DSA_DEFINE_INTERFACE_POINTERS
/**
 * Define this if the platform header should be included.
 */
#define OGL_DSA_INCLUDE_PLATFORM_HEADER
/**
 * Define this if the open gl extension header should be included.
 */
#define OGL_DSA_INCLUDE_EXT_HEADER
/**
 * Define this if the open gl platform specific extension should be included.
 */
#define OGL_DSA_INCLUDE_FPLATFORM_EXT_HEADER
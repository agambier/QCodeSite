//	CodeSite library.
//
//	History:
//		v1.00 - June 12, 2014 - A.Gambier
//		- File creation
//		- Added functions:
//			+ CodeSite_Clear
//			+ CodeSite_EnterMethod
//			+ CodeSite_ExitMethod
//			+ CodeSite_Message
//			+ CodeSite_Error
//			+ CodeSite_Warning
//			+ CodeSite_Reminder
//			+ CodeSite_Note
//			+ CodeSite_Category
//			+ CodeSite_AddCheckPoint
//			+ CodeSite_ResetCheckPoint
//			+ CodeSite_AddSeparator
//			+ CodeSite_AddResetSeparator

#ifndef __CodeSiteDll_H__
#define	__CodeSiteDll_H__

#define	CODESITE_VERSION	0x0100

//	4-byte alignment: MSVC & Borland
#pragma pack( push, 4 )

//	API macro
#if defined( CODESITE_EXPORT_DLL )
	#define CODESITE_API __declspec( dllexport ) __stdcall
#else
	#if defined(  __BORLANDC__ )
		#define CODESITE_API __declspec( dllimport ) __stdcall
	#endif	//	__BORLANDC__

	#if defined( _MSC_VER )
		#define CODESITE_API
	#endif	//	_MSC_VER

	#if defined( __GNUC__ )
		#define CODESITE_API
	#endif	//	__GNUC__
#endif	//	CODESITE_EXPORT_DLL

//	Use va_list ?
#if defined( CODESITE_USE_VALIST )
	#define	CODESITE_VALIST	, ...
	#define	CODESITE_VALIST_PREFIX	"_"
#else
	#define	CODESITE_VALIST	/**/
	#define	CODESITE_VALIST_PREFIX	/**/
#endif	//	CODESITE_USE_VALIST

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// CodeSite TYPES
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

//	Struct:	TCodeSiteError
//		Known error code list.
typedef enum _TCodeSiteError
{
	cserrOk = 0,					//	Success.
	cserrFailed, 				//	Process failed.
	cserrNotImplemented,			//	Function not implemented.
	cserrInvalidParameter,		//	A parameter is invalid.
	cserrInvalidFileFormat,		//	File format is invalid.
	cserrMissingFunction,		//	An exported function is missing.
	cserrDllNotFound,			//	DLL not found.
	cserrCantCreateTempFile,		//	Can't create temporary file.
	cserrFileNotOpen,			//	The file is not open.
	cserrUnsupportedLanguage,	//	Unsupported language.
	cserrFileNotFound,			//	File not found.
	cserrFILL = 0xFFFFFFFF,		//	Force compiler to handle enums on 4 bytes.
} TCodeSiteError ;

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// EXPORTED FUNCTIONS
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#if defined( __cplusplus )
	extern "C" {
#endif	//	__cplusplus

#if defined( CODESITE_EXPORT_DLL ) || defined( CODESITE_STATIC_DLL )
//	----- Static library -----

// ---------------------------------------------------------------------------
//	Function:	CodeSite_Clear
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Clear( void );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_EnterMethod( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_ExitMethod( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:	
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Message( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Error( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Warning( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Reminder( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Note( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_Category( const wchar_t *pwszText CODESITE_VALIST );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_AddCheckPoint( void );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_ResetCheckPoint( void );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_AddSeparator( void );

// ---------------------------------------------------------------------------
//	Function:
//
//	Parameters:
// ---------------------------------------------------------------------------
void CODESITE_API CodeSite_AddResetSeparator( void );

#else
//	----- Dynamic library -----
typedef void ( __stdcall *TCodeSite_Clear )( void );
typedef void ( __stdcall *TCodeSite_EnterMethod )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_ExitMethod )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_Message )(const  wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_Error )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_Warning )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_Reminder )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_Note )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_Category )( const wchar_t *pwszText CODESITE_VALIST );
typedef void ( __stdcall *TCodeSite_AddCheckPoint )( void );
typedef void ( __stdcall *TCodeSite_ResetCheckPoint )( void );
typedef void ( __stdcall *TCodeSite_AddSeparator )( void );
typedef void ( __stdcall *TCodeSite_AddResetSeparator )( void );


#endif	//	CODESITE_EXPORT_DLL || CODESITE_STATIC_DLL

#if defined( __cplusplus )
	}
#endif	//	__cplusplus

#if !defined( CODESITE_EXPORT_DLL ) && !defined( CODESITE_STATIC_DLL )
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// DYNAMIC LOADING FUNCTIONS AND MACROS
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <windows.h>

#if defined( CODESITE_DYNAMIC_DLL_PUBLIC )
	#define CODESITE_DLL_EXTERN	/**/
#else
	#define CODESITE_DLL_EXTERN	extern
#endif	//	!CODESITE_DYNAMIC_DLL_PUBLIC

//	----- Function pointers declaration -----
CODESITE_DLL_EXTERN HINSTANCE g_tCodeSite_HInstance;
CODESITE_DLL_EXTERN TCodeSite_Clear CodeSite_Clear;
CODESITE_DLL_EXTERN TCodeSite_EnterMethod CodeSite_EnterMethod;
CODESITE_DLL_EXTERN TCodeSite_ExitMethod CodeSite_ExitMethod;
CODESITE_DLL_EXTERN TCodeSite_Message CodeSite_Message;
CODESITE_DLL_EXTERN TCodeSite_Error CodeSite_Error;
CODESITE_DLL_EXTERN TCodeSite_Warning CodeSite_Warning;
CODESITE_DLL_EXTERN TCodeSite_Reminder CodeSite_Reminder;
CODESITE_DLL_EXTERN TCodeSite_Note CodeSite_Note;
CODESITE_DLL_EXTERN TCodeSite_Category CodeSite_Category;
CODESITE_DLL_EXTERN TCodeSite_AddCheckPoint CodeSite_AddCheckPoint;
CODESITE_DLL_EXTERN TCodeSite_ResetCheckPoint CodeSite_ResetCheckPoint;
CODESITE_DLL_EXTERN TCodeSite_AddSeparator CodeSite_AddSeparator;
CODESITE_DLL_EXTERN TCodeSite_AddResetSeparator CodeSite_AddResetSeparator;

TCodeSiteError CodeSite_FreeDll( void );
TCodeSiteError CodeSite_LoadDll( wchar_t *pwszDll = NULL );

#if defined( CODESITE_DYNAMIC_DLL_PUBLIC )
TCodeSiteError CodeSite_LoadFunctions( void )
{
	if( ( CodeSite_Clear = ( TCodeSite_Clear )GetProcAddress( g_tCodeSite_HInstance, "CodeSite_Clear" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_EnterMethod = ( TCodeSite_EnterMethod )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_EnterMethod" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_ExitMethod = ( TCodeSite_ExitMethod )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_ExitMethod" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_Message = ( TCodeSite_Message )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_Message" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_Error = ( TCodeSite_Error )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_Error" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_Warning = ( TCodeSite_Warning )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_Warning" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_Reminder = ( TCodeSite_Reminder )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_Reminder" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_Note = ( TCodeSite_Note )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_Note" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_Category = ( TCodeSite_Category )GetProcAddress( g_tCodeSite_HInstance, CODESITE_VALIST_PREFIX "CodeSite_Category" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_AddCheckPoint = ( TCodeSite_AddCheckPoint )GetProcAddress( g_tCodeSite_HInstance, "CodeSite_AddCheckPoint" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_ResetCheckPoint = ( TCodeSite_ResetCheckPoint )GetProcAddress( g_tCodeSite_HInstance, "CodeSite_ResetCheckPoint" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_AddSeparator = ( TCodeSite_AddSeparator )GetProcAddress( g_tCodeSite_HInstance, "CodeSite_AddSeparator" ) )==NULL ) return cserrMissingFunction;
	if( ( CodeSite_AddResetSeparator = ( TCodeSite_AddResetSeparator )GetProcAddress( g_tCodeSite_HInstance, "CodeSite_AddResetSeparator" ) )==NULL ) return cserrMissingFunction;

	return cserrOk;
}

TCodeSiteError CodeSite_FreeDll( void )
{
	if( g_tCodeSite_HInstance!=NULL )
		FreeLibrary( g_tCodeSite_HInstance );

	return cserrOk;
}

TCodeSiteError CodeSite_LoadDll( const wchar_t *pwszDll )
{
	TCodeSiteError tResult = cserrDllNotFound;

	//	Load the DLL
	if( pwszDll==NULL )
		g_tCodeSite_HInstance = LoadLibrary( L"CodeSite.dll" );
	else
		g_tCodeSite_HInstance = LoadLibrary( pwszDll );

	if( g_tCodeSite_HInstance!=NULL )
	{
		//	Load the exported functions.
		tResult = CodeSite_LoadFunctions();
		if( tResult!=cserrOk )
			CodeSite_FreeDll();
	}

	return tResult;
}
#endif	//	CODESITE_DYNAMIC_DLL_PUBLIC
#endif	//	!CODESITE_EXPORT_DLL && !CODESITE_STATIC_DLL


//	Pop alignment settings
#pragma pack(pop)

#endif	//	__CodeSiteDll_H__

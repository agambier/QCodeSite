#ifndef DEBUG_H
#define DEBUG_H

#include <QString>
#if defined( QT_DEBUG )
	#include <QDebug>
	#include <typeinfo>

	#if !defined( DEBUG_WITH_QDEBUG )
		#include "codesite.h"
	#endif	//	DEBUG_WITH_QDEBUG
#endif	//	QT_DEBUG

#endif // DEBUG_H


//	Code debugging macros
#if defined( QT_DEBUG )
	#define	DEBUG_CODE( code )		code;
	#define	DEBUG_CODE_H( code )	code;
#else
	#define	DEBUG_CODE( code )		( ( void )0 );
	#define	DEBUG_CODE_H( code )
#endif	//	QT_DEBUG


//	Macro with optional parameters
//	check out : http://stackoverflow.com/questions/3046889/optional-parameters-with-c-macros
//	Formatting up to 19 parameters
#define FORMAT_1( fmt )		QString( fmt )
#define FORMAT_2( fmt, A1 )		QString( fmt ).sprintf( A1 )
#define FORMAT_3( fmt, A1, A2 )		QString( fmt ).sprintf( A1, A2 )
#define FORMAT_4( fmt, A1, A2, A3 )		QString( fmt ).sprintf( A1, A2, A3 )
#define FORMAT_5( fmt, A1, A2, A3, A4 )		QString( fmt ).sprintf( A1, A2, A3, A4 )
#define FORMAT_6( fmt, A1, A2, A3, A4, A5 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5 )
#define FORMAT_7( fmt, A1, A2, A3, A4, A5, A6 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6 )
#define FORMAT_8( fmt, A1, A2, A3, A4, A5, A6, A7 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7 )
#define FORMAT_9( fmt, A1, A2, A3, A4, A5, A6, A7, A8 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8 )
#define FORMAT_10( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9 )
#define FORMAT_11( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10 )
#define FORMAT_12( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11 )
#define FORMAT_13( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12 )
#define FORMAT_14( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13 )	QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13 )
#define FORMAT_15( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14 )	QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14 )
#define FORMAT_16( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15 ) 	QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15 )
#define FORMAT_17( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16 )		QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16 )
#define FORMAT_18( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17 )	QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17 )
#define FORMAT_19( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18 )	 QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18 )
#define FORMAT_20( fmt, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19 )	QString( fmt ).sprintf( A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19 )

#define FORMAT_FUNC( A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, FUNC, ... ) 	FUNC
#define FORMAT_MACRO_SELECT( ... )	FORMAT_FUNC( __VA_ARGS__,	\
									FORMAT_20, \
									FORMAT_19, \
									FORMAT_18, \
									FORMAT_17, \
									FORMAT_16, \
									FORMAT_15, \
									FORMAT_14, \
									FORMAT_13, \
									FORMAT_12, \
									FORMAT_11, \
									FORMAT_10, \
									FORMAT_9, \
									FORMAT_8, \
									FORMAT_7, \
									FORMAT_6, \
									FORMAT_5, \
									FORMAT_4, \
									FORMAT_3, \
									FORMAT_2, \
									FORMAT_1, )
#define	FORMAT( ... )	FORMAT_MACRO_SELECT(__VA_ARGS__)( __VA_ARGS__ )

#if defined( QT_DEBUG )
	#if !defined( DEBUG_WITH_QDEBUG )
		#define DEBUG_INIT( _dll_ )				Debug::CodeSite::initialize( _dll_, true )
		#define DEBUG_CLEAR()					Debug::CodeSite::clear()
		#define DEBUG_ENTERMETHOD()				Debug::CodeSite::enterMethod( __PRETTY_FUNCTION__ )
		#define DEBUG_EXITMETHOD()				Debug::CodeSite::exitMethod( __PRETTY_FUNCTION__ )
		#define DEBUG_MESSAGE( ... )			Debug::CodeSite::message( FORMAT( __VA_ARGS__ ) )
		#define DEBUG_ERROR( ... )				Debug::CodeSite::error( FORMAT( __VA_ARGS__ ) )
		#define DEBUG_WARNING( ... )			Debug::CodeSite::warning( FORMAT( __VA_ARGS__ ) )
		#define DEBUG_REMINDER( ... )			Debug::CodeSite::reminder( FORMAT( __VA_ARGS__ ) )
		#define DEBUG_NOTE( ... )				Debug::CodeSite::note( FORMAT( __VA_ARGS__ ) )
		#define DEBUG_CATEGORY( ... )			Debug::CodeSite::category( FORMAT( __VA_ARGS__ ) )
		#define DEBUG_ADDCHECKPOINT()			Debug::CodeSite::addCheckPoint()
		#define DEBUG_RESETCHECKPOINT()			Debug::CodeSite::resetCheckPoint()
		#define DEBUG_ADDSEPARATOR()			Debug::CodeSite::addSeparator()
		#define DEBUG_ADDRESETSEPARATOR()		Debug::CodeSite::addResetSeparator()
	#else
		#define DEBUG_INIT( _dll_ )				( ( void )0 )
		#define DEBUG_CLEAR()					( ( void )0 )
		#define DEBUG_ENTERMETHOD()				qDebug() << FORMAT( "> %1", __PRETTY_FUNCTION__ )
		#define DEBUG_EXITMETHOD()				qDebug() << FORMAT( "< %1", __PRETTY_FUNCTION__ )
		#define DEBUG_MESSAGE( ... )			qDebug() << FORMAT( __VA_ARGS__ )
		#define DEBUG_ERROR( ... )				qCritical() << FORMAT( __VA_ARGS__ )
		#define DEBUG_WARNING( ... )			qWarning() << FORMAT( __VA_ARGS__ )
		#define DEBUG_REMINDER( ... )			qDebug() << FORMAT( __VA_ARGS__ )
		#define DEBUG_NOTE( ... )				qDebug() << FORMAT( __VA_ARGS__ )
		#define DEBUG_CATEGORY( ... )			( ( void )0 )
		#define DEBUG_ADDCHECKPOINT()			( ( void )0 )
		#define DEBUG_RESETCHECKPOINT()			( ( void )0 )
		#define DEBUG_ADDSEPARATOR()			qDebug() << "------------------------------------------------------------------------"
		#define DEBUG_ADDRESETSEPARATOR()		qDebug() << "========================================================================"
	#endif	//	DEBUG_WITH_QDEBUG
#else
	#define DEBUG_INIT( _dll_ )				( ( void )0 )
	#define DEBUG_CLEAR()					( ( void )0 )
	#define DEBUG_ENTERMETHOD()				( ( void )0 )
	#define DEBUG_EXITMETHOD()				( ( void )0 )
	#define DEBUG_MESSAGE( ... )			( ( void )0 )
	#define DEBUG_ERROR( ... )				( ( void )0 )
	#define DEBUG_WARNING( ... )			( ( void )0 )
	#define DEBUG_REMINDER( ... )			( ( void )0 )
	#define DEBUG_NOTE( ... )				( ( void )0 )
	#define DEBUG_CATEGORY( ... )			( ( void )0 )
	#define DEBUG_ADDCHECKPOINT()			( ( void )0 )
	#define DEBUG_RESETCHECKPOINT()			( ( void )0 )
	#define DEBUG_ADDSEPARATOR()			( ( void )0 )
	#define DEBUG_ADDRESETSEPARATOR()		( ( void )0 )
#endif	//	QT_DEBUG


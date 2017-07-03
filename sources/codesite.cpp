#include "codesite.h"
#define CODESITE_DYNAMIC_DLL_PUBLIC
#include "CodeSiteDll.h"

namespace Debug {

bool CodeSite::m_bIsInitialized = false;

//	Function:	CodeSite_MessageHandler
//		Message handler when qDebug(), qWarning() functions.
void CodeSite_MessageHandler( QtMsgType tType, const QMessageLogContext &tContext, const QString &tText )
{
	Q_UNUSED( tContext );

	switch( tType )
	{
		case QtWarningMsg:
			CodeSite::warning( tText );
			break;

		case QtCriticalMsg:
		case QtFatalMsg:
			CodeSite::error( tText );
			break;

		case QtDebugMsg:
		default:
			CodeSite::message( tText );
			break;
	}
}

//
//
//
CodeSite::CodeSite()
{

}

//
//
//
CodeSite::~CodeSite()
{
	if( false != m_bIsInitialized )
	{
		CodeSite_FreeDll();
		m_bIsInitialized = false;
	}
}

//
//
//
bool CodeSite::initialize( const QString &tCodeSiteDll, bool bRedirectQDebug )
{
	if( false == m_bIsInitialized )
	{
		//	Load the library
		if( cserrOk == CodeSite_LoadDll( ( 0 == tCodeSiteDll.length() ) ? NULL : ( wchar_t* )tCodeSiteDll.utf16() ) )
		{
			m_bIsInitialized = true;

			//	Redirect qDebug()
			if( false != bRedirectQDebug )
			{
				qInstallMessageHandler( CodeSite_MessageHandler );
			}
		}
	}
	return m_bIsInitialized;
}

//
//
//
void CodeSite::clear()
{
	if( false != m_bIsInitialized )
		CodeSite_Clear();
}

//
//
//
void CodeSite::enterMethod(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_EnterMethod( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::exitMethod(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_ExitMethod( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::message(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_Message( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::error(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_Error( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::warning(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_Warning( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::reminder(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_Reminder( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::note(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_Note( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::category(const QString &tText)
{
	if( false != m_bIsInitialized )
		CodeSite_Category( ( wchar_t* )tText.utf16() );
}

//
//
//
void CodeSite::addCheckPoint()
{
	if( false != m_bIsInitialized )
		CodeSite_AddCheckPoint();
}

//
//
//
void CodeSite::resetCheckPoint()
{
	if( false != m_bIsInitialized )
		CodeSite_ResetCheckPoint();
}

//
//
//
void CodeSite::addSeparator()
{
	if( false != m_bIsInitialized )
		CodeSite_AddSeparator();
}

//
//
//
void CodeSite::addResetSeparator()
{
	if( false != m_bIsInitialized )
		CodeSite_AddResetSeparator();
}


}


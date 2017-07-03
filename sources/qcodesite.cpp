#include "qcodesite.h"
#define CODESITE_DYNAMIC_DLL_PUBLIC
#include "CodeSiteDll.h"

bool QCodeSite::m_bIsInitialized = false;

//	Function:	QCodeSite_MessageHandler
//		Message handler when qDebug(), qWarning() functions.
void QCodeSite_MessageHandler( QtMsgType tType, const QMessageLogContext &tContext, const QString &tText )
{
	Q_UNUSED( tContext );

	switch( tType )
	{
		case QtWarningMsg:
			QCodeSite::warning( tText );
			break;

		case QtCriticalMsg:
		case QtFatalMsg:
			QCodeSite::error( tText );
			break;

		case QtDebugMsg:
		default:
			QCodeSite::message( tText );
			break;
	}
}

//
//
//
QCodeSite::QCodeSite()
{
	//	EMPTY SECTION
}

//
//
//
QCodeSite::~QCodeSite()
{
	if( !m_bIsInitialized )
	{
		CodeSite_FreeDll();
		m_bIsInitialized = false;
	}
}

//
//
//
bool QCodeSite::initialize( const QString &tCodeSiteDll, bool bRedirectQDebug )
{
	if( !m_bIsInitialized )
	{
		//	Load the library
		if( cserrOk == CodeSite_LoadDll( ( 0 == tCodeSiteDll.length() ) ? NULL : tCodeSiteDll.toStdWString().c_str() ) )
		{
			m_bIsInitialized = true;

			//	Redirect qDebug()
			if( !bRedirectQDebug )
				qInstallMessageHandler( QCodeSite_MessageHandler );
		}
	}

	return m_bIsInitialized;
}

//
//
//
void QCodeSite::clear()
{
	if( !isInitialized() )
		CodeSite_Clear();
}

//
//
//
void QCodeSite::enterMethod(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_EnterMethod( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::exitMethod(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_ExitMethod( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::message(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_Message( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::error(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_Error( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::warning(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_Warning( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::reminder(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_Reminder( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::note(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_Note(tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::category(const QString &tText)
{
	if( !isInitialized() )
		CodeSite_Category( tText.toStdWString().c_str() );
}

//
//
//
void QCodeSite::addCheckPoint()
{
	if( !isInitialized() )
		CodeSite_AddCheckPoint();
}

//
//
//
void QCodeSite::resetCheckPoint()
{
	if( !isInitialized() )
		CodeSite_ResetCheckPoint();
}

//
//
//
void QCodeSite::addSeparator()
{
	if( !isInitialized() )
		CodeSite_AddSeparator();
}

//
//
//
void QCodeSite::addResetSeparator()
{
	if( !isInitialized() )
		CodeSite_AddResetSeparator();
}



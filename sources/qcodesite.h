#ifndef CODESITE_H
#define CODESITE_H

#include <QString>
#include <QDebug>


class QCodeSite
{
	public:
		QCodeSite();
		~QCodeSite();

		static bool initialize( const QString &tCodeSiteDll = "", bool bRedirectQDebug = true );

		static inline bool isInitialized() {
			return m_bIsInitialized;
		}

		static void clear();

		static void enterMethod( const QString &tText );
		static void exitMethod( const QString &tText );

		static void message( const QString &tText );
		static void error( const QString &tText );
		static void warning( const QString &tText );
		static void reminder( const QString &tText );
		static void note( const QString &tText );

		static void category( const QString &tText );

		static void addCheckPoint();
		static void resetCheckPoint();

		static void addSeparator();
		static void addResetSeparator();

	protected:
		static bool m_bIsInitialized;
};




#endif // CODESITE_H

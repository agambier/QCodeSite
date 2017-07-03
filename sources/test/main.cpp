#include "mainwindow.h"
#include <QApplication>
#include "..\qcodesite.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	if( !QCodeSite::initialize() )
		return -1;

	w.show();

	return a.exec();
}

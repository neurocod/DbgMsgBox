//by neurocod as Konstantine Kozachuk, BSD license, 2020.03.29
//see README.md
#include "pch.h"
#include "DbgMsgBox.h"

int main(int argc, char* argv[]) {
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
	a.setOrganizationName("neurocod");
	a.setOrganizationDomain("neurocod@");
	{
		QFont font = a.font();
		font.setPointSize(12);
		a.setFont(font);
	}
	QString text;
#ifdef Q_OS_WIN
	QCoreApplication::setAttribute(Qt::AA_DisableWindowContextHelpButton);
	if (argc > 1) {
		auto strTitle = ::GetCommandLineW();
		text = QString::fromWCharArray(strTitle);
	} else {
		text = "no cmd line";
	}
#else
#error
#endif
	DbgMsgBox w;
	w.setTextFromCommandLine(text);
	return w.exec();
}

//for test compilation:
#include "msgBox.h"
//#include "D:\dev\DbgMsgBox\DbgMsgBox\msgBox.h"
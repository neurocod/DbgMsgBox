#include "pch.h"
#include "DbgMsgBox.h"

DbgMsgBox::DbgMsgBox(QWidget *parent): QDialog(parent, Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint) {
	auto lay = new QVBoxLayout(this);
	lay->setMargin(2);
	lay->setSpacing(1);
	lay->addWidget(_tabs);
	lay->addWidget(_statusBar);

	_tabs->addTab(_text, "text");
	_tabs->addTab(_json, "json");
	resize({1024, 768});

	auto act = new QAction(tr("Exit"));
	act->setShortcut(QKeySequence("Ctrl+Q"));
	connect(act, &QAction::triggered, this, &QDialog::reject);
	addAction(act);
}
void DbgMsgBox::setTextFromCommandLine(const QString& commandLine) {
	QString text = commandLine;
	//auto appName = qApp->applicationName();
	//int index = commandLine.indexOf(appName);
	auto path = QCoreApplication::applicationFilePath();
	int index = 0;
	if (text.startsWith('"'))
		index++;
	QString maybePath = text.mid(index, path.length());
	path = QDir::toNativeSeparators(path);
	maybePath = QDir::toNativeSeparators(maybePath);
	if (maybePath == path) {
		index += path.length();
		if (text.at(0) == '"')
			index++;
		if (text.at(index) == ' ')
			index++;
		text = text.mid(index);
	}
	//if(text.contains(path))
	//if (-1 != index) {
	//	index += appName.length() + 1;
	//	text = commandLine.mid(index);
	//}
	setText(text);
}
void DbgMsgBox::setText(const QString& s) {
	_statusBar->showMessage(QString("%1 characters").arg(s.length()));
	_text->setPlainText(s);

	QString json = s;
	if (s.startsWith("http")) {
		auto lines = s.split('\n');
		lines.removeFirst();
		json = lines.join('\n');
	}
	QJsonParseError err;
	QJsonDocument doc = QJsonDocument::fromJson(json.toLocal8Bit(), &err);
	if (err.error == QJsonParseError::NoError) {
		_json->setPlainText(doc.toJson(QJsonDocument::Indented));
		_tabs->setCurrentIndex(1);
	} else {
		_json->setPlainText("Error");
		_tabs->setCurrentIndex(0);
	}
}
#pragma once

class DbgMsgBox : public QDialog
{
	Q_OBJECT

public:
	DbgMsgBox(QWidget *parent = Q_NULLPTR);
	void setText(const QString& s);
	void setTextFromCommandLine(const QString & s);

	QTabWidget* _tabs = new QTabWidget;
	QTextEdit* _text = new QTextEdit;
	QTextEdit* _json = new QTextEdit;
	QStatusBar* _statusBar = new QStatusBar;
};

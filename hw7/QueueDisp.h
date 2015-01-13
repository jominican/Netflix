#ifndef QUEUEDISP_H
#define QUEUEDISP_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QString>
#include <string>
#include "Netflix.h"
//#include "MainScreen.h"

#include <iostream>

// helper function

class QueueDisp : public QMainWindow //display the queue window for title search
{
	Q_OBJECT
	public:
		QueueDisp(QMainWindow *parent, Netflix * n);
		~QueueDisp();

	private:

		QLabel 				 * movieInfo;
		QLabel 				 * movieTitle;
		QLabel 				 ** keywords;

		QPushButton    * addToQueue;
		QPushButton    * returnToMain;	

		//QPlainTextEdit * txtWordsInput;
		QVBoxLayout    * movieLayout;

		QHBoxLayout    * buttonLayout;
		QWidget        * centerWidget;

		Netflix  			 * netflix;

		QMainWindow    * p;

		Set<string> tempMapKeyWords;
		Set<string>::Iterator setIter;

		int size;

	private slots:
		void addToMyQueue();
		void returnToMainMenu();
		void closeEvent(QCloseEvent *x);


};

#endif
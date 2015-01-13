#ifndef QUEUEDISP1_H
#define QUEUEDISP1_H

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

#include <iostream>

// helper function

class QueueDisp1 : public QMainWindow //display the queue window for keyword search
{
	Q_OBJECT
	public:
		QueueDisp1(QMainWindow *parent, Netflix * n);
		~QueueDisp1();

	private: //qt layout variables

		QLabel 				 * movieInfo;
		QLabel 				 * movieTitle;
		QLabel 				 * keywords;

		QPushButton    * nextMovie;
		QPushButton    * addToQueue;
		QPushButton    * returnToMain;	

		QVBoxLayout    * movieLayout;

		QHBoxLayout    * buttonLayout;
		QWidget        * centerWidget;

		Netflix  			 * netflix;

		QMainWindow    * p;

		Set<string> tempMapKeyWords;
		Set<string>::Iterator setIter;

		string line;

		int size;

	private slots:
		void next();
		void addToMyQueue();
		void returnToMainMenu();
		void closeEvent(QCloseEvent *x);


};

#endif
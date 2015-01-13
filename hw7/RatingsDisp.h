#ifndef RATINGSDISP_H
#define RATINGSDISP_H

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
#include "RatingScreen.h"

#include <iostream>

// helper function

class RatingsDisp : public QMainWindow //display the queue window for keyword search
{
	Q_OBJECT
	public:
		RatingsDisp(QMainWindow *parent, Netflix * n);
		~RatingsDisp();

	private: //qt layout variables

		QLabel 				 * movieInfo;
		QLabel 				 * movieTitle;

		QPushButton    * rate;
		QPushButton    * nextMovie;
		QPushButton    * returnToMain;	

		QVBoxLayout    * movieLayout;

		QHBoxLayout    * buttonLayout;
		QWidget        * centerWidget;

		Netflix  			 * netflix;

		QMainWindow    * p;

		Set<string> tempMapKeyWords;
		Set<string>::Iterator setIter;

		string line;


	private slots:
		void next();
		void change();
		void returnToMainMenu();
		void closeEvent(QCloseEvent *x);


};

#endif
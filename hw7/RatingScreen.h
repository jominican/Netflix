#ifndef RATINGSCREEN_H
#define RATINGSCREEN_H

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

// helper function

class RatingScreen : public QMainWindow
{
	Q_OBJECT
	public:
		RatingScreen(QMainWindow *parent, Netflix * netflix); //display the mainscreen after user logs in
		~RatingScreen();

	private:

		QLabel 				 * ratings;

		QPushButton    * one;
		QPushButton    * two;
		QPushButton    * three;
		QPushButton    * four;
		QPushButton    * five;
		QPushButton    * noRating;


		QVBoxLayout    * mainLayout;

		QHBoxLayout    * button1Layout;

		QWidget        * centerWidget;

		Netflix  			 * netflix;

		QMainWindow 	 * p;


	private slots:
		void closeEvent(QCloseEvent *x);
		void oneS();
		void twoS();
		void threeS();
		void fourS();
		void fiveS();
		void noRatingS();
		

};

#endif
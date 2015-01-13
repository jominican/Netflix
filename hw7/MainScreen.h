#ifndef MAINSCREEN_H
#define MAINSCREEN_H

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
#include "QueueDisp.h"
#include "QueueDisp1.h"
#include "RatingScreen.h"
#include "RatingsDisp.h"

// helper function

class MainScreen : public QMainWindow
{
	Q_OBJECT
	public:
		MainScreen(QMainWindow *parent, Netflix * netflix); //display the mainscreen after user logs in
		~MainScreen();

	private:

		QLabel 				 * mainScreenLabel;
		QLabel 				 * label1;
		QLabel 				 * label2;
		QLabel 				 * label3;
		QLabel 				 * currentMovieLabel;
		QLabel 				 * currentQueueLabel;
		QLabel         * priceLabel;

		QLineEdit 		 * search;
		QLineEdit      * pass;

		QFormLayout 	 * searchRow;
		QFormLayout 	 * passRow;

		QPushButton    * returnButton;
		QPushButton    * rentButton;
		QPushButton    * deleteQueueButton;
		QPushButton    * moveBackButton;
		QPushButton    * searchByTitleButton;
		QPushButton    * searchByKeywordButton;
		QPushButton    * searchByActorButton;
		QPushButton    * logoutButton;
		QPushButton    * refreshButton;
		QPushButton    * viewRatings;
		QPushButton    * no;
		QPushButton    * changePass;

		QVBoxLayout    * mainLayout;

		QHBoxLayout    * button1Layout;
		QHBoxLayout    * button2Layout;
		QHBoxLayout    * button3Layout;
		QHBoxLayout    * button4Layout;
		QHBoxLayout    * button5Layout;
		QHBoxLayout    * button6Layout;


		QWidget        * centerWidget;

		Netflix  			 * netflix;

		QMainWindow 	 * p;

		QMessageBox 	 * msg;

	private slots:
		void returnMovie();
		void rentMovie();
		void deleteFromQueue();
		void moveToBack();
		void refresh();
		void searchByTitle();
		void searchByKeyword();
		void searchByActor();
		void view();
		void changing();
		void logout();
		void closeEvent(QCloseEvent *x);
		

};

#endif
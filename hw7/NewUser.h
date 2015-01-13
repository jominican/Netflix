#ifndef NEWUSER_H
#define NEWUSER_H

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
#include <string.h>
#include <cstring>
#include "Netflix.h"

using namespace std;

class NewUser : public QMainWindow
{
	Q_OBJECT
	public:
		NewUser(QMainWindow *parent, Netflix * n);//display the newUser window
		~NewUser();

	private:

		QLabel 				 * signupLabel;

		QLineEdit 		 * login;
		QLineEdit      * name;
		QLineEdit      * password;
		QLineEdit      * address;
		QLineEdit      * card;

		QFormLayout 	 * loginRow;
		QFormLayout    * signupRow;

		QPushButton    * confirmButton;
		QPushButton    * cancelButton;
		
		QVBoxLayout    * newuserLayout;

		QHBoxLayout    * buttonLayout;
		
		QWidget        * centerWidget;

		Netflix        * netflix;

		QMainWindow    * p;

		//QMainWindow

	private slots:
		void confirm();
		void cancel();
		void closeEvent(QCloseEvent *x);
		// void quit();
		

};

#endif
# CS 104 Project Repository

- **Name**: Joseph Wu
- **USC ID**: 5461457990
- **Email**: shuhanwu@usc.edu

All the files are located in their respective folder. 
eqe.h, Map.h, MapImpl.h, MergeSort.h Set.h, SetImpl.h, nsee.h, Queue.h, and QueueImpl.h are in lib (nsee.h & eqe.h are the classes for custom exception)
main.txt, user.txt, movie.txt are in data folder (special user1.txt can be ignored)
bin folder will initially have nothing until the files are made. When made, it will have hw4, MergeSortTest, and SetTest executable

Movie.cpp, Movie.h, User.cpp, User.h, hw4.cpp and makefile are all in the main directory because they have specific functionality


***FOR HOMEWORK 6***
building the assignment for hw6:
make

running the assignment for hw6:
./hw4 data/main.txt (make sure to add "data/" to whichever file you are running)


***FOR HOMEWORK 7***
All the homework 7 files are located in the hw7 folder (.h, .cpp, makefile, moc, everything)
First: Go to the hw7 folder with cd hw7

building the assignment for hw7:
qmake -project
qmake
make

running the assignment:
./hw7 main.txt

One thing to keep in mind: Whenever a movie is not showing up in the front of the queue property or at any time when it is supposed to, click "refresh" to refresh the queue and the movies will be displayed properly. 


***FOR HOMEWORK 10***
All the homework 10 files are located in the hw7 folder (.h, .cpp, makefile, moc, everything)
First: Go to the hw7 folder with cd hw7

building the assignment for hw10:
qmake -project
qmake
make

running the assignment:
./hw7 /data/main.txt

Bells and Whistles Done 
 - (*1 bell and whistle*) Actors
 - (*4 bells and whistles*) Partial Keyword Search works for titles and keywords. Trie implementation can be seen in trie.h in the libs folder
 - (*2 bells and whistles*) User Fields. All passwords are automatically set to "csci104" (without quotations) for every user. The password that is shown in user file is stored in encrypted text. 
 - (*1 bell and whistle*) Modify Ratings
 - (*4 bells and whistles*) Your own Hash Table. Hashtable implementation can be seen in the Hash.h/HashImpl.h files in the libs folder. However, due to last minute bugs that would cause nothing to run, I was not able to fully convert all maps to hashtables. 
 - (*Total*) possible 12

(*Things to keep in mind when grading*) because I chose some bells and whistles that causes changes to the user and movie txt files, I have provided sample files named user.txt and movie.txt. If you choose to run the program with your own test files, there's a possible that it will cause an error, because those test files might not include things such as ratings, addresses, password, etc. Also, I did not do steps 1 & 2 for the homework, because I am hoping my extra work in bells and whistles can make up for the points lost. I did do step 0. 


Enjoy Netflics!


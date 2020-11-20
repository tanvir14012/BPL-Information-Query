# BPL-Information-Query
A File I/O based console application developed in C programming language that let users query for useful information such as team information, player information, rankings, searching, individual performance etc. about  Bangladesh Premier League (BPL), a T20 Cricket tournament. This is developed as part of my Software Development Project-I. There are two versions of the application: 

1. Static: Uses static arrays, arrays of structures.

2. Dynamic : Added a feature "Promising players of 2016" for both batsman and bowler category, from the performance of BPL 2013 and BPL 2015 best ten probable players are predicted. This accomplished by combining each player's performance of BPL 2013 and 2015 into a new memory space and  sorting them based on multiple criteria such as: average, runs/wickets, strike_rate/ economy and then selecting the top ten. The "void player_prediction(int key);" function implements the feature and stores the results in a file, upon query from the user, results are displayed from the file.
It also uses dynmaic arrays, arrays of structures using pointers arithmetic. It was instructed by my professor to replace the application by pointer arithmetic and add the "Promising players of 2016" feature.

# Features
- Predicts the promising players for the future BPL 2016 event by analyzing the performance of players in BPL 2013 and 2015.
- Smooth console navigation menu
- Top ten bowler and batsman's performance statistics
- Team information query
- Player search and information display
- Player navigation and information display
- Team ranking

# EXIF Viewer and RPS
I created this program as an assignment for the University of Pittsburgh's Introduction to System Software course (COE 0449).  The main feature is an EXIF Viewer, which takes a `.jpg` image file and prints the meta-data found in the EXIF tag.  The secondary feature is a game of Rock, Paper, Scissors.  Both are implemented in `C`.
## EXIF Viewer
A C Program which takes a .jpg as input and prints information found in the EXIF tag.

Compile: `gcc -o exifview exifview.c`  
Execute: `./exifview FILENAME`

Example:
```
$ gcc -o exifview exifview.c
$ ./exifview img2.jpg
Manufacturer:   Canon
Model:          Canon PowerShot SX100 IS
Exposure Time:  1/60 second
F-stop:         f/8.0
ISO:            ISO 100
Date Taken:     2008:02:20 18:52:03
Focal Length:   60  mm
Width:          360 pixels
Height:         240 pixels

```


## Rock, Paper, Scissors
A pretty self-explanatory Rock, Paper, Scissors game in C. The player plays a "Best of 5" series with the computer whose responses are (psuedo)randomly generated.

Compile: `gcc -o rps rps.c`  
Execute: `./rps`

Example:  
```
$ gcc -o rps rps.c
$ ./rps
Welcome to Rock, Paper, Scissors.
The rules are simple:
1)Rock smashes Scissors
2)Scissors cut Paper
3)Paper covers Rock.

Good Luck.
Would you like to play? yes
Round 1. What is your choice? rock
he computer picked Paper! You lose this game!
he score is now You: 0 Computer: 1


Round 2. What is your choice? paper
The computer picked Paper! This game was a tie!
The score is now You: 0 Computer: 1


Round 3. What is your choice? scissors
The computer picked Scissors! This game was a tie!
The score is now You: 0 Computer: 1
```

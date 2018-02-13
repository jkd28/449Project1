# EXIF Viewer
I created this program as an assignment for the University of Pittsburgh's Introduction to System Software course (COE 0449).  This `C` program is an EXIF Viewer, which takes a `.jpg` image file and prints the information/meta-data found in the EXIF tag.  

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

# KeyLopper-cpp
 A semi advanced keylogger implemented in C++ .
 The keylogger Stores all the keystrokes of the user while running in hidden mode i.e. It can only be seen running via Task Manager (not in task bar ) . It writes all the keystrokes in a file named "logs.txt"  . 

On first start up the program fetches it's  location and on the target pc and then adds itself to the autorun directory of the system (only for Windows )

 So the executable file has to be runned only once on target windows system and then on every windows bootup  it would automatically start in the background and writes all the keystrokes dynamically into the file (after every keystroke ).
 
 ## Way Forward
Add email feature based on SMTP client so as to mail the stored keystrokes to the intruder .
Also after every successful mail eraze all the contents of the file "logs.txt" so as to prevent excess memory usage and remain undetected .

## Note-
->This peice of code is written and shared for Learning Purpose only and No harm is Intended . Use it at your own discretion !!

->Any help , advice will be highly appreciated 
### !Thank You!


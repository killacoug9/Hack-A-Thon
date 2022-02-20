# Hack-A-Thon
Hack-a-thon project 
Good Morning Judges, We apologize for the jank code. We seem to have bit off a little more than we could chew however we are very proud of what we learned and what 
we managed to accomplish. Going into this hackathon we had no idea how an IRC server or client worked and our goal was folishly to try and create an IRC server and 
client that could run our project idea of a platform where cougs could meet and talk to each other. We learned pretty quick that building your own IRC server back end
was not as simple as we thought. Through out the day we worked towards a basic understanding of multithreading and sockets while having no knowledge about them at the 
start of the day. We managed to get our server code to work although we have had some problems with it working on computers other than the one it was mainly programmed 
on (possible due to our complete lack of knowledge when it comes to how git works). We also couldn't get the client to fully work, however through the use of PUTTY we could test 
our server code. For testing the  server code, make sure that the global variable called "IS_SERVER" is set to 1 in the server.h file, you will also need to set the ip 
address to your current IP and the port to a valid port for your computer (I am sure you know this but if you need to find that info go to cmd and type 'netstat -n'). 
Also if testing the client make sure that same variable is set to 0. Finally we had plans to add an entire GUI, you can even see some primative attempts commented out, 
however through the sheer time it took to "learn" sockets and multithreading we did not have time to even really work on the GUI. Through out the day we have learned 
many lesson, not only what sockets are and a very basic under standing of multithreading, we also learned that using multithreading is byfar not the best way to make an 
irc server back end.

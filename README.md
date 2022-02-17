# zoomchEt
Okey funny story!

I'm often on Zoom meetings using my linux machine and today I found myself in an awkward predicament. I was in a small breakout room and really needed to get up as I was lossing all the feeling in bottom...
I knew that switching of the video would be very sus and didn't want to bring any attention to myself in the current set of circumstances...
so I brought up the linux terminal I had in the background and sent a kill SIGTOP signal to the zoom process, causing my zoom to simply pause temporarily, until I sent the kill SIGCONT signal to contiue the process where it left of... It came across as a connection issue and no-one noticed.

After the meeting was over I threw together this quick and dirty script in C so I can more easily automate the process in the future should I ever want to unsuspiciously "loose connection" temporariliy again.

I recommend setting up a keyboard shortcut that will run the script in the background on command.

I'm using 
  ```alt + s for "zoomchEt sleep"```
  ```alt + w for "zoomchEt wake"```
  ```alt + b for "zoomchEt bye"```

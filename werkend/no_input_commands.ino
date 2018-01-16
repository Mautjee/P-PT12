bool drive = false;
void Readmessage(String theMessage) {
  theMessage.toUpperCase();
  if (theMessage == "REMOTE_CONTROL") {
    //
  }
  else if (theMessage == "LOCAL_CONTROL") {
    //
  }
  else if (theMessage == "TEST") {
    serialwrite("testing if this works");
  }
  else if (theMessage == "DRIVE") {
    if (drive)
    {
        //disable driving
        drive = false;
    }
    else
    {
        //enable driving
        drive = true;
    }
    serialwrite("Driving... I guess");
  }
  else {
    getRemoteMessage(theMessage);
  }
}

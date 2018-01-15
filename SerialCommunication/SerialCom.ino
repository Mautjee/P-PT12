//Hier code plaatsten voor het ontvangen van commands.
//Onderstaande if statement nesten op de locatie waar de characters 1 voor 1 worden binnengehaald.
    if (readChar == '#' || command == true) { //vervang de # door command openingsteken
      command = true;
      message += readChar; //maakt een volledig command uit characters
      if (readChar == '%') { //vervang de % door command sluitteken
        command = false;  //reset de command check, command begint pas weer als het openingsteken binnenkomt
        Serial.println(message); //debug extra controle
        message = ""; //cleared de string voor volgende command
      }
    }

//
